# Code Review Report: UVa 401 - Palindromes

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 401
- **Problem Title:** Palindromes
- **Problem Link:** https://onlinejudge.org/external/4/401.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 2 次，2026-11-10）
- **Source Code (Initial/Fail):** [src/s1151536-UVa401_fail.cpp](./src/s1151536-UVa401_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa401.cpp](./src/s1151536-UVa401.cpp)（最新一次提交，尚未 AC）
- **Review Date:** 2026-11-17

## 2. Problem Statement in My Own Words

> ✍️ **TODO（請用自己的話完成）**：輸入是什麼？輸出是什麼？主要規則與限制？核心任務？（不要複製原題）

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

> ✍️ **TODO（請用自己的話完成）**：第一個想法是什麼？一開始注意到哪些困難？為什麼初版不夠？

### Final Strategy

> ✍️ **TODO（請用自己的話完成）**：最後用了什麼方法？為什麼可行？考慮了哪些邊界情況？

### Complexity Analysis

- **Time Complexity:**
- **Space Complexity:**

> ✍️ **TODO（請用自己的話完成）**：說明為何符合題目限制。

## 4. Pseudocode

> ✍️ **TODO（請用自己的話完成）**：依照你的最終程式寫出主要步驟。

```text
START
1.
2.
3.
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	string chars = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	while(cin >> s){
		bool PALINDROME=true;
		long long n=s.size();
		for (int i=0; i<n/2; i++){
			if(s[i] == '0'){
				s[i] = 'O';
			}
		}
		for (int i=0; i<n/2; i++){
			if(s[i] != s[n-i-1]){
				PALINDROME = false;
				break;
			}
		}
		bool mirror=true;
		for (int i=0; i<n/2; i++){
			char mirrored = ' ';
			if(s[i] >= int('A') && s[i] <= int('Z')){
				mirrored = chars[int(s[i])-int('A')];
			}else{
				mirrored = chars[int(s[i])-int('1')+26];
			}
			//cout << s[i] << " " << mirrored << endl;
			if(s[n-i-1] != mirrored){
				mirror = false;
				break;
			}
			
		}
		
		cout << s;
		if(PALINDROME && mirror){
			cout << " -- is a mirrored palindrome." << endl;
			continue;
		}
		if(!PALINDROME && !mirror){
			cout << "  -- is not a palindrome." << endl;
			continue;
		}
		if(!PALINDROME && mirror){
			cout << " -- is a mirrored string." << endl;
			continue;
		}
		if(PALINDROME && !mirror){
			cout << " -- is a regular palindrome." << endl;
			continue;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- **輸出格式**：UVa 401 規定每一行輸出後要再接一個**空行**，兩個版本都沒有輸出空行。
- **中間字元沒檢查**：鏡像判斷只跑 `i < n/2`，長度為奇數時中間的字元沒有檢查自己是否能鏡像。例如 `ABA`（B 無法鏡像）應為 regular palindrome，程式輸出 mirrored palindrome。
- 失敗版本中非字母字元一律用數字公式查表，遇到其他字元可能越界；最新版本已加上 else 處理。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	string chars = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	while(cin >> s){
		int n=s.size();
		for (int i=0; i<n; i++){
			if(s[i] == '0'){
				s[i] = 'O';
			}
		}
		
		bool PALINDROME=true;
		for (int i=0; i<n/2; i++){
			if(s[i] != s[n-i-1]){
				PALINDROME = false;
				break;
			}
		}
		
		bool mirror=true;
		for (int i=0; i<n/2; i++){
			char mirrored = ' ';
			if(s[i] >= int('A') && s[i] <= int('Z')){
				mirrored = chars[int(s[i])-int('A')];
			}else if(int(s[i])>=int('1') && int(s[i])<=int('9')){
				mirrored = chars[int(s[i])-int('1')+26];
			}else{
				mirror = false;
				break;
			}
			//cout << s[i] << " " << mirrored << endl;
			if(s[n-i-1] != mirrored){
				mirror = false;
				break;
			}
			
		}
		
		cout << s;
		if(PALINDROME && mirror){
			cout << " -- is a mirrored palindrome." << endl;
			continue;
		}
		if(!PALINDROME && !mirror){
			cout << "  -- is not a palindrome." << endl;
			continue;
		}
		if(!PALINDROME && mirror){
			cout << " -- is a mirrored string." << endl;
			continue;
		}
		if(PALINDROME && !mirror){
			cout << " -- is a regular palindrome." << endl;
			continue;
		}
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
   1. 每次輸出結果後多印一個 `endl`（空行）。
   2. 鏡像檢查的迴圈改成 `i <= (n-1)/2`（或 `i < (n+1)/2`），讓中間字元也和自己比對。
- 鏡像對照表字串 `"A   3  HIL JM O   2TUVWXY51SE Z  8 "` 本身是正確的。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | NOTAPALINDROME<br>ISAPALINILAPASI<br>2A3MEAS<br>ATOYOTA | 每行結果後各接一個空行 | 結果正確但沒有空行 | 題目範例 |
| Edge | ABA | ABA -- is a regular palindrome. | ABA -- is a mirrored palindrome. | 奇數長度、中間字元無鏡像 |

⚠️ 有 2 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | 未處理其他字元 | 加上 else |
| Edge Cases | 中間字元未檢查 | 仍未檢查 |
| Output Handling | 缺少空行 | 仍缺少 |
| Complexity | O(n) | O(n) |
| Code Quality | 同 | 同 |

### Reflection

- **Root cause:**
- **Lesson learned:**
- **Next action:**

> ✍️ **TODO（請用自己的話完成）**：根據上面的診斷，寫下你自己的反思。

## 8. AI Usage Disclaimer

- AI tools, if used, were used only to support learning, such as clarifying concepts or reviewing explanations.
- I independently understood, verified, and completed the solution and reflection in this report.

### AI Usage Record

| Problem ID / Title | AI Tool Used | How It Was Used | Verification Performed Independently |
|---|---|---|---|
| UVa 401 / Palindromes | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
