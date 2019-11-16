#include <iostream>
using namespace std;

struct teacher{
	int id;
	char name[64];
};

void getMem(teacher** pTeacher){
	teacher* pt;
	pt = (teacher*)malloc(sizeof(teacher));

	pt->id = 10;
	strcpy_s(pt->name,"ahlin");

	*pTeacher = pt;//ָ���ֵ = pt ֵ
}

void freeMem(teacher** pTeacher) {
	if (*pTeacher != NULL)
	{
		free(*pTeacher);
		*pTeacher = NULL;
	}
}

//ָ������� pTeacher ���� pTher�ı���
void getMem2(teacher*& pTeacher)
{
	pTeacher = (teacher*)malloc(sizeof(teacher));
	pTeacher->id = 20;
	strcpy_s(pTeacher->name, "ahlin");
}

//�ͷ�
void freeMem2(teacher*& pTeacher) {
	if (pTeacher != NULL)
	{
		free(pTeacher);
		pTeacher = NULL;
	}
}

int main(void) {
	teacher* pTher;

	getMem(&pTher);
	cout << "ID:" << pTher->id << " name:" << pTher->name << endl;
	freeMem(&pTher);

	getMem2(pTher);
	cout << "ID:" << pTher->id << " name:" << pTher->name << endl;
	freeMem2(pTher);
}