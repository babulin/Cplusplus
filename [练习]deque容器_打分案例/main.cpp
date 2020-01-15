#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define PLAYER_NUM 5  //��Ҹ���
#define SET_SCORE_NUM 10 //��ִ���

class Player {
public:
	string mName;
	int mScore;
public:
	Player() {};
	Player(string name, int score) :mName(name), mScore(score){
	};
};

//for_each �ص�
void ShowDeque(int score) {
	cout << score << " ";
}


//��������
void CreatePlayer(vector<Player> &vp) {
	
	string nameSeed = "ABCDE";
	for (int i = 0; i < PLAYER_NUM; i++){
		string tName = "ѡ��";
		tName += nameSeed[i];
		Player p(tName, 0);
		vp.push_back(p);
	}
}

//���÷���
void SetScore(vector<Player>& vp) {
	for (vector<Player>::iterator ivp = vp.begin(); ivp != vp.end(); ivp++)
	{
		//��ѧ������10�δ��
		deque<int> dScore;
		for (int i = 0; i < SET_SCORE_NUM; i++)
		{
			int tScore = rand() % 41 + 60;//(0~40 + 60)
			dScore.push_back(tScore);
		}

		//���� [int Ĭ����������]
		sort(dScore.begin(), dScore.end());

		//��ӡ
		//for_each(dScore.begin(), dScore.end(), ShowDeque);
		//cout << endl;

		//ȥ����ͷֺ���߷�
		dScore.pop_back();//ȥ����߷�
		dScore.pop_front();//ȥ����ͷ�

		//��ƽ����
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end() ; dit++){
			totalScore += (*dit);
		}

		int avgScore = totalScore / dScore.size();

		//���뵱ǰ������
		(*ivp).mScore = avgScore;
	}
}

//����������
bool ScoreDesc(Player& p1, Player& p2) {
	return p1.mScore > p2.mScore;
}

//��ʾ���а�
void ShowRank(vector<Player>& vp) {
	//����
	sort(vp.begin(), vp.end(), ScoreDesc);

	//��ӡ
	for (vector<Player>::iterator ivp = vp.begin(); ivp != vp.end(); ivp++)
	{
		cout << "������" << (*ivp).mName << " ������" << (*ivp).mScore << endl;
	}
}

int main() {
	//����
	vector<Player> vpList;
	CreatePlayer(vpList);

	//���
	SetScore(vpList);

	//��ʾ����
	ShowRank(vpList);

}