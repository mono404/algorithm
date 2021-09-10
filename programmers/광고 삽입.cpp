#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int timeToSec(string time)
{
	int hour = stoi(time.substr(0, 2));
	int min = stoi(time.substr(3, 2));
	int sec = stoi(time.substr(6, 2));

	return (hour * 3600) + (min * 60) + sec;
}

string secToTime(int sec)
{
	int h = sec / 3600;
	sec %= 3600;
	int m = sec / 60;
	int s = sec % 60;

	string H, M, S;

	if (h < 10)
		H = "0" + to_string(h);
	else
		H = to_string(h);

	if (m < 10)
		M = "0" + to_string(m);
	else
		M = "" + to_string(m);

	if (s < 10)
		S = "0" + to_string(s);
	else
		S = "" + to_string(s);

	return H + ":" + M + ":" + S;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";

	vector<int> timeTable(360000, 0);

	int Play_Time = timeToSec(play_time);
	int Adv_Time = timeToSec(adv_time);

	for (int i = 0; i < logs.size(); i++)
	{
		int start_t = timeToSec(logs[i].substr(0, 8));
		int end_t = timeToSec(logs[i].substr(9, 8));
		
		for (int j = start_t + 1; j <= end_t; j++)
		{
			timeTable[j]++;
		}
	}

	long long playTime = 0;
	long long maxPlayTime = 0;
	long long ans = 1;

	for (int i = 1; i <= Adv_Time; i++)
	{
		playTime += timeTable[i];
	}

	maxPlayTime = playTime;

	for (int i = 2; i <= (Play_Time - Adv_Time + 1); i++)
	{
		playTime += (long long)(timeTable[i + Adv_Time - 1] - timeTable[i - 1]);

		if (playTime > maxPlayTime)
		{
			maxPlayTime = playTime;
			ans = i;
		}
	}

	answer = secToTime(ans - 1);

	return answer;
}

int main(void)
{
	cout << solution("02:03:55", "00:14:15", { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" }) << endl;
	cout << solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" }) << endl;
	cout << solution("50:00:00", "50:00:00", { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" }) << endl;
}
