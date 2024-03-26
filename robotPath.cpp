#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
 
struct Segment {
	LL x1, y1, x2, y2;
	int id;
	void swap_xy() {
		swap(x1, y1);
		swap(x2, y2);
	}
	// bool operator <(const Segment& he) const {
		// return false;
	// }
};
 
vector<Segment> vertical, horizontal;
int max_val = 0;
 
void initialize_segments(vector<pair<char, int>> commands) {
	int n = commands.size();
	long long x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		char dir = commands[i].first;
		int len = commands[i].second;
		if (dir == 'U') {
			vertical.push_back(Segment{x, y+bool(i), x, y+len, i});
			y += len;
		}
		else if (dir == 'D') {
			vertical.push_back(Segment{x, y-len, x, y-bool(i), i});
			y -= len;
		}
		else if (dir == 'R') {
			horizontal.push_back(Segment{x+bool(i), y, x+len, y, i});
			x += len;
		}
		else if (dir == 'L') {
			horizontal.push_back(Segment{x-len, y, x-bool(i), y, i});
			x -= len;
		}
		else {
			assert(false);
		}
	}
}
 
void swap_xy() {
	swap(vertical, horizontal);
	for (Segment& seg : vertical) {
		seg.swap_xy();
	}
	for (Segment& seg : horizontal) {
		seg.swap_xy();
	}
}
 
void coordinate_compression() {
	for (int rep = 0; rep < 2; rep++) {
		swap_xy();
		// compress only x below
		vector<LL> xs;
		for (auto v : {vertical, horizontal}) {
			for (Segment seg : v) {
				xs.push_back(seg.x1);
				xs.push_back(seg.x2);
			}
		}
		sort(xs.begin(), xs.end());
		xs.resize( unique(xs.begin(), xs.end()) - xs.begin() );
		max_val = max(max_val, (int) xs.size());
		auto fix_x = [&](LL& x) {
			x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
		};
		for (Segment& seg : vertical) {
			fix_x(seg.x1);
			fix_x(seg.x2);
		}
		for (Segment& seg : horizontal) {
			fix_x(seg.x1);
			fix_x(seg.x2);
		}
	}
}
 
struct Event {
	int x, type;
	Segment seg;
	bool operator <(const Event& he) const {
		return make_pair(x, type) < make_pair(he.x, he.type);
	}
};
 
int vertical_horizontal_intersect(bool do_segtree) {
	// gather and sort the events for SWEEP LINE
	
	//     ((x, type),  segment)
	vector<Event> events;
	const int START = 0, VERT = 1, END = 2;
	for (Segment seg : horizontal) {
		events.emplace_back(Event{(int)seg.x1, START, seg});
		events.emplace_back(Event{(int)seg.x2, END, seg});
	}
	
	for (Segment seg : vertical) {
		events.emplace_back(Event{(int)seg.x1, VERT, seg});
	}
	sort(events.begin(), events.end());
	
	vector<set<int>> ids(max_val);
	// ids[y] -- set of ids of horizontal segments at y
	
	// create MIN segment tree
	int BASE = 1;
	while (BASE < max_val) {
		BASE *= 2;
	}
	vector<int> tree(2*BASE, INT_MAX); // min tree with ids
	
	auto getMin = [&](int L, int R) {
		if (!do_segtree) {
			return INT_MAX;
		}
		assert(L <= R);
		L += BASE;
		R += BASE;
		int small = min(tree[L], tree[R]);
		while (L + 1 < R) {
			if (L % 2 == 0) small = min(small, tree[L+1]);
			if (R % 2 == 1) small = min(small, tree[R-1]);
			L /= 2;
			R /= 2;
		}
		return small;
	};
	auto update = [&](int i) {
		if (!do_segtree) {
			return;
		}
		tree[BASE+i] = (ids[i].empty() ? INT_MAX : *ids[i].begin());
		for (int j = (BASE + i) / 2; j >= 1; j /= 2) {
			tree[j] = min(tree[2*j], tree[2*j+1]);
		}
	};
	
	int first_bad = vertical.size() + horizontal.size(); // n
	
	// iterate events
	for (const Event& event : events) {
		if (event.type == VERT) {
			int other_id = getMin(event.seg.y1, event.seg.y2);
			first_bad = min(first_bad, max(event.seg.id, other_id));
		}
		else if (event.type == START) {
			ids[event.seg.y1].insert(event.seg.id);
			update(event.seg.y1);
			
			// horizontal-horizontal intersection
			set<int>& s = ids[event.seg.y1];
			if ((int) s.size() >= 2) {
				auto it = s.begin();
				it++;
				first_bad = min(first_bad, *it);
			}
		}
		else if (event.type == END) {
			ids[event.seg.y1].erase(event.seg.id);
			update(event.seg.y1);
		}
	}
	
	return first_bad;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<char,int>> commands(n);
	for (int i = 0; i < n; i++) {
		cin >> commands[i].first >> commands[i].second;
	}
	
	initialize_segments(commands);
	auto memo = vector<vector<Segment>>{vertical, horizontal}; // before compression
	coordinate_compression();
	
	// Get all vertical & horizontal segments.
	// For each segment, find the intersection with smallest id.
	// If intersection id is smaller that this segment, this seg is bad.
	
	int a = vertical_horizontal_intersect(true);
	swap_xy();
	int b = vertical_horizontal_intersect(false);
	int first_bad = min(a, b);
	if (first_bad == n) {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += commands[i].second;
		}
		cout << sum << endl;
		return 0;
	}
	
	
	// Then second phase, focusing on first bad segment.
	vertical = memo[0];
	horizontal = memo[1];
	
	Segment special;
	special.id = -1;
	for (Segment seg : vertical) {
		if (seg.id == first_bad) {
			special = seg;
		}
	}
	for (Segment seg : horizontal) {
		if (seg.id == first_bad) {
			special = seg;
		}
	}
	assert(special.id != -1);
	
	auto orig_commands = commands;
	char& dir = commands[special.id].first;
	if (dir == 'U' || dir == 'D') {
		// vertical
		swap_xy();
		special.swap_xy();
		if (dir == 'U') dir = 'R';
		else if (dir == 'D') dir = 'L';
		else assert(false);
	}
	// extend special segment by 1
	if (special.id != 0) {
		if (dir == 'R') {
			special.x1--;
		}
		else if (dir == 'L') {
			special.x2++;
		}
		else {
			assert(false);
		}
	}
	// cout << special.x1 << " " << special.x2 << " " << special.y1 << endl;
	// special is horizontal
	long long special_len = INT_MAX;
	for (Segment vert : vertical) {
		if (vert.id < special.id - 1) {
			if (special.x1 <= vert.x1 && vert.x1 <= special.x2
				&& vert.y1 <= special.y1 && special.y1 <= vert.y2) {
				// cout << "vert.y = " << vert.y1 << "," << vert.y2 << "   x=" << vert.x1 << endl;
				special_len = min(special_len, (dir == 'R' ? vert.x1 - special.x1 : special.x2 - vert.x1));
			}
		}
	}
	for (Segment hor : horizontal) {
		if (hor.id < special.id) {
			if (hor.id == special.id - 1 && orig_commands[hor.id].first == orig_commands[special.id].first) {
				continue;
			}
			if (special.y1 == hor.y1 && !(special.x2 < hor.x1 || hor.x2 < special.x1)) {
				long long L = max(special.x1, hor.x1);
				long long R = min(special.x2, hor.x2);
				// [L, R]
				special_len = min(special_len, (dir == 'R' ? L - special.x1 : special.x2 - R));
			}
		}
	}
	// cout << "id = " << special.id << endl;
	assert(special_len != INT_MAX);
	for (int i = 0; i < special.id; i++) { 
		special_len += commands[i].second;
	}
	cout << special_len << endl;
}