#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define PLAYER_NUM 5  //玩家个数
#define SET_SCORE_NUM 10 //打分次数

class Player {
public:
	string mName;
	int mScore;
public:
	Player() {};
	Player(string name, int score) :mName(name), mScore(score){
	};
};

//for_each 回调
void ShowDeque(int score) {
	cout << score << " ";
}


//创建对象
void CreatePlayer(vector<Player> &vp) {
	
	string nameSeed = "ABCDE";
	for (int i = 0; i < PLAYER_NUM; i++){
		string tName = "选手";
		tName += nameSeed[i];
		Player p(tName, 0);
		vp.push_back(p);
	}
}

//设置分数
void SetScore(vector<Player>& vp) {
	for (vector<Player>::iterator ivp = vp.begin(); ivp != vp.end(); ivp++)
	{
		//对学生进行10次打分
		deque<int> dScore;
		for (int i = 0; i < SET_SCORE_NUM; i++)
		{
			int tScore = rand() % 41 + 60;//(0~40 + 60)
			dScore.push_back(tScore);
		}

		//排序 [int 默认排序升序]
		sort(dScore.begin(), dScore.end());

		//打印
		//for_each(dScore.begin(), dScore.end(), ShowDeque);
		//cout << endl;

		//去除最低分和最高分
		dScore.pop_back();//去除最高分
		dScore.pop_front();//去除最低分

		//求平均分
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end() ; dit++){
			totalScore += (*dit);
		}

		int avgScore = totalScore / dScore.size();

		//放入当前对象中
		(*ivp).mScore = avgScore;
	}
}

//按分数降序
bool ScoreDesc(Player& p1, Player& p2) {
	return p1.mScore > p2.mScore;
}

//显示排行榜
void ShowRank(vector<Player>& vp) {
	//排名
	sort(vp.begin(), vp.end(), ScoreDesc);

	//打印
	for (vector<Player>::iterator ivp = vp.begin(); ivp != vp.end(); ivp++)
	{
		cout << "姓名：" << (*ivp).mName << " 分数：" << (*ivp).mScore << endl;
	}
}

int main() {
	//创建
	vector<Player> vpList;
	CreatePlayer(vpList);

	//打分
	SetScore(vpList);

	//显示排名
	ShowRank(vpList);

}