#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<string> nums;
    int i = 0, j = 0, n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    string tmp;
    while(n > 0) {
        cout << "Enter [" << i << "]: ";
        cin >> tmp;
        nums.push_back(tmp);
        n--;
        i++;
    }
    for(i = 0; i < nums.size(); i++) {
        for(j = 0; j < nums.size(); j++) {
            if(lexicographical_compare(nums[i].begin(), nums[i].end(), nums[j].begin(), nums[j].end())) {
                swap(nums[i], nums[j]);
            }
        }
    }
    for(i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}
