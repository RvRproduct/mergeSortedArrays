#include <iostream>
#include <vector>

using namespace std;

std::vector<int> mergeSortedArrays(std::vector<int> const &v1, std::vector<int> const &v2);

std::vector<int> mergeSortedArrays(std::vector<int> const &v1, std::vector<int> const &v2) {
    std::vector<int> mA{};
    std::vector<int> mSA{};
    int index {0};
    
    // merged array
    for (auto item: v1)
        mA.push_back(item);
    for (auto item: v2)
        mA.push_back(item);
        
    // sorted array
    while (mSA.size() < mA.size()) {
        
        if (mSA.size() == 0)
            mSA.push_back(mA[index]);
        
        if ((mA.size() - 1) - index >= 0) {
            if (mSA[index] <= mA[index + 1] && index < (static_cast<int>(mA.size()) - 1)) {
                mSA.push_back(mA[index + 1]);
            } else {
                for (int i = 0; i < (static_cast<int>(mSA.size())); i++) {
                    if (index == (static_cast<int>(mA.size()) - 1)) {
                        if (mSA[i] >= mA[index]) {
                            mSA.insert(mSA.begin() + i, mA[index]);
                            break;
                        }
                    } else {
                        if (mSA[i] >= mA[index + 1]) {
                            mSA.insert(mSA.begin() + i, mA[index + 1]);
                            break;
                        }
                    }
                }
            }
            index++;
        }
    }
    return mSA;
}

int main(){
    
    for (auto item: mergeSortedArrays({0, 3, 4, 31}, {4, 3, 30}))
        cout << item << " ";
    cout << endl;
    return 0;
}