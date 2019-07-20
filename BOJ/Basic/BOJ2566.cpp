#include <iostream>
using namespace std;

int mp[9][9];
int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin>>mp[i][j];
		}
	}
	
	int ans = 0, row = 0, col = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(ans < mp[i][j]){
				row = i + 1;
				col = j + 1;
				ans = mp[i][j];	
			}
		}
	}
	cout<<ans<<endl;
	cout<<row<<' '<<col<<endl;
	
	return 0;
}
