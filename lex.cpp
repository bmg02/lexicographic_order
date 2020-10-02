#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> nums;
    int i = 0, j = 0, n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    string tmp;
    while(n--) {
        cout << "Enter [" << i << "] th element :";
        cin >> tmp;
        nums.push_back(tmp);
        i++;
    }
    for(i = 0; i < nums.size()-1; i++) {
        for(j = 0; j < nums.size()-i-1; j++) {
            if(lexicographical_compare(nums[j].begin(), nums[j].end(), nums[j+1].begin(), nums[j+1].end())) {
                swap(nums[j], nums[j+1]);
            }
            
        }
    }
    reverse(nums.begin(),nums.end());
    for(i = 0; i < nums.size(); i++) {
        cout << nums[i] << "\n";
    }
}