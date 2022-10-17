#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

vector<string> filecall(vector<string> st)		// 파일 입력
{
	ifstream fp;								// 파일변수
	string line;								// 입력변수
	string filename;							// 파일 이름

	cout << " 파일 이름 : ";
	cin >> filename;

	fp.open(filename);
	if (fp.is_open())
	{
		while (!fp.eof())						// 파일 읽기
		{
			getline(fp, line);
			for (int a = 0; a < line.size(); a++)
			{
				if ((line[a] >= 97 && line[a] <= 122) || (line[a] >= 65 && line[a] <= 90)) {}	//아스키 코드, 소문자 a~z = 97~122, 대문자 A~Z = 65~90
				else
				{
					line.erase(line.begin() + a);		// 알파벳이 아닐때 
					a = -1;
				}
			}
			st.push_back(line);
		}
	}
	else
	{
		cout << " 일치하는 파일이 없습니다. 프로그램을 종료합니다." << endl;
		exit(0);
	}
	fp.close();
	return st;
}

void pal(vector<string> st)			// 회문
{
	int check = 0;
	for (int a = 0; a < st.size(); a++)
	{
		if (st[a].size() == 1)										// 문자 하나
			cout << " " << a + 1 << ".	회문 X" << endl;
		else if (equal(st[a].begin(), st[a].end(), st[a].rbegin()))	// 회문 판단
		{
			cout << " " << a + 1 << ".	회문 O" << endl;
			check++;
		}
		else														// 회문 x
			cout << " " << a + 1 << ".	회문 X" << endl;
	}
	cout << "-------------------------------------" << endl;
	cout << " 회문은 총 " << check << "개 입니다." << endl;
}

vector<string> case_(vector<string> st)		// 예외, 대소문자 구문 없이 하고 싶을 때 넣으면 된다.
{
	for (int a = 0; a < st.size(); a++)	// 모두 대문자로 변경
	{
		transform(st[a].begin(), st[a].end(), st[a].begin(), toupper);
	}
	return st;
}

void main()
{
	system("mode con cols=100 lines=30");		// 콘솔 창 크기
	vector<string> st;						// 문장/문자 저장 벡터
	st = filecall(st);						// 파일 입력
	//st = case_(st);							// 대 소문자 상관 없이 판별하고 싶을 때, 대문자로 바꾼다
	pal(st);									// 회문판독
	system("pause");
}


