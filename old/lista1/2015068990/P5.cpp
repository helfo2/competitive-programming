#include <iostream>
#include <vector>

using namespace std;

int n;

void print(vector<int>& v){
    for(auto it : v){
        cout << it << " ";
    }
    
    cout << endl;
}

int solve(){
    vector<int> country;
    
    for(int i = 1; i <= n; i++){
        country.push_back(i);
    }
    
    bool ans = false;
    int m;
    for(m = 1; m <= n; m++){
        vector<int> temp(n);
        copy(country.begin(), country.end(), temp.begin());
        // cout << "for m = " << m << " and size = " << temp.size() <<  endl;
        int j = 0;
        while(temp.size() > 1){
            // print();
            // cout << temp.at(j) << endl;
            temp.erase(temp.begin()+j);
            j= (j + m - 1)%temp.size();
            
        }
        // cout << "got out" << endl;
        if(temp.front() == 13){
            ans = true;
            break;
        } else {
            ans = false;
        }
    }
    
    if(ans){
        return m;
    } else {
        return -1;
    }
}

int main() {
	while(cin >> n, n!=0){
	   // cout << "m = " << solve() << endl;
	   cout << solve() << endl;
	}
	
	return 0;
}