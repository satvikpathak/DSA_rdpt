// class Solution {
// public:
//     void swap(char* a, char* b){
//         int temp = *a;
//         *a=*b;
//         *b=temp;
//         }

//     void reverseString(vector<char>& s) {
//         for(int i=0; i<s.size()/2; i++){
//             swap(&s[i], &s[s.size()-1-i]);
//         }
//     }
// };

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int left = 0;
//         int right = s.size() - 1;

//         while(left<right){
//             char temp = s[left];
//             s[left] = s[right];
//             s[right] = temp;

//             left ++;
//             right --;
//         }
//     }
// };