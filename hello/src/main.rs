use std::io::{self, BufRead};

const N: usize = 75;
const INF: i32 = 1e9 as i32;

fn main() {
    let stdin = io::stdin();
    let mut stdin_lock = stdin.lock();
    let mut line = String::new();
    stdin_lock.read_line(&mut line).unwrap();
    let mut iter = line.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();

    let mut a = vec![vec![0; m]; n];

    for i in 0..n {
        line.clear();
        stdin_lock.read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        for j in 0..m {
            a[i][j] = iter.next().unwrap().parse().unwrap();
        }
    }

    let mut dp = vec![vec![vec![vec![-INF; k]; m / 2 + 1]; m]; n + 1];
    dp[0][0][0][0] = 0;
    for i in 0..n {
        for j in 0..m {
            for cnt in 0..=m / 2 {
                for rem in 0..k {
                    if dp[i][j][cnt][rem] == -INF {
                        continue;
                    }
                    let ni = if j == m - 1 { i + 1 } else { i };
                    let nj = if j == m - 1 { 0 } else { j + 1 };
                    if i != ni {
                        dp[ni][nj][0][rem] = dp[ni][nj][0][rem].max(dp[i][j][cnt][rem]);
                    } else {
                        dp[ni][nj][cnt][rem] = dp[ni][nj][cnt][rem].max(dp[i][j][cnt][rem]);
                    }
                    if cnt + 1 <= m / 2 {
                        let nrem = (rem + a[i][j]) % k;
                        if i != ni {
                            dp[ni][nj][0][nrem] =
                                dp[ni][nj][0][nrem].max(dp[i][j][cnt][rem] + a[i][j]);
                        } else {
                            dp[ni][nj][cnt + 1][nrem] =
                                dp[ni][nj][cnt + 1][nrem].max(dp[i][j][cnt][rem] + a[i][j]);
                        }
                    }
                }
            }
        }
    }

    println!("{}", dp[n][0][0][0].max(0));
}
