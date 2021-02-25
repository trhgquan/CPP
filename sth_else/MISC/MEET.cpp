/**
 * MEET - https://codechef.com/FEB21C/problems/MEET
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

struct Time {
  int Time, minute;
} typedef Time;

// y >= x
bool isLarger(Time x, Time y) {
  return (x.Time > y.Time) || (x.Time >= y.Time && x.minute >= y.minute);
}

bool isValid(Time start, Time end, Time schedule) {
  return isLarger(schedule, start) && isLarger(end, schedule);
}

bool isAM(string s) {
  return (s == "AM");
}

Time convert(string p_Time, string p_day) {
  Time res;
  sscanf(p_Time.c_str(), "%d:%d", &res.Time, &res.minute);
  if (isAM(p_day)) {
    if (res.Time == 12) res.Time = 0;
  } else {
    if (res.Time != 12) res.Time += 12;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    string p_Time, p_day; cin >> p_Time >> p_day;
    int n; cin >> n;
    Time p = convert(p_Time, p_day);
    vector<bool>parray;
    for (int i = 0; i < n; ++i) {
      string p_start, p_end, p_Time_start, p_Time_end;
      cin >> p_start >> p_Time_start >> p_end >> p_Time_end;

      parray.push_back(isValid(convert(p_start, p_Time_start), convert(p_end, p_Time_end), p));
    }

    for (auto it : parray) cout << it;
    cout << '\n';
  }

  return 0;
}
