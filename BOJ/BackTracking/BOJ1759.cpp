#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> v;
vector<bool> visit(26);
vector<bool> init(26);
int L, C;

//해당 문자열이 가지고 있는 알파벳으로 만들 수 있는지
//최소 한개의 모음과 최소 두 개의 자음으로 구성 
bool check(){
	int vowal = 0; //모음의 개수
	int consonant = 0; //자음의 개수
	
	if(visit[0]) vowal++;
	if(visit[4]) vowal++;
	if(visit[8]) vowal++;
	if(visit[14]) vowal++;
	if(visit[20]) vowal++;
	
	for(int i=0; i<26; i++){
		if(i==0 || i==4 || i==8 || i==14 || i==20)
			continue;
		if(visit[i]){
			consonant++;
		}
	}
	
	if(vowal > 0 && consonant > 1){
		return true;
	}else{
		return false;
    }
}

//string : 누적되는 문자열
//cnt : 현재 몇개까지 더해졌는지
//s : 알파벳 순서
//암호는 알파벳이 증가하는 순서로 배열한다. 
void solve(string str, int cnt, int s){
	int idx = v[s] - 'a';
	visit[idx] = true;
	
	if(cnt == L){ //종료조건
		if(check()){
			cout<<str<<'\n';			
		}
	}else{
		for(int i=s+1; i<C; i++){
			//다음 알파벳을 사용하지 않았다면 
			if(visit[v[i]-'a'] == false){
				solve(str+v[i], cnt+1, i);//사용	
			}
		}
	}
	//backTracking
	visit[idx] = false;
}

int main(){
	cin>>L>>C;
	for(int i=0; i<C; i++){
		char ch;
		cin>>ch;
		v.push_back(ch);
	}
	sort(v.begin(), v.end());
	
	string str = "";
	for(int i=0; i<=C-L; i++){
		visit = init; //방문 초기화 
		solve(str + v[i], 1, i);
	}
	return 0;
}
