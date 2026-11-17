# Code Review Report: UVa 272 - TeX Quotes

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 272
- **Problem Title:** TeX Quotes
- **Problem Link:** https://onlinejudge.org/external/2/272.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 4 次，2026-11-10）
- **Source Code (Initial/Fail):** [src/s1151536-UVa272_fail.cpp](./src/s1151536-UVa272_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa272.cpp](./src/s1151536-UVa272.cpp)
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
	int sin=0, pur=0;
	string s="";
	while(getline(cin ,s)){
		for (char c : s){
			if(int(c) == 39){
				if(sin%2==0){
					cout << "`";
				}else{
					cout << "'";
				}
				sin++;
			}else if (int(c) == 34){
				if(pur%2==0){
					cout << "``";
				}else{
					cout << "''";
				}
				pur++;
			}else{
				cout << c;
			}
		}
		cout << endl;
	}
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 題目只要求轉換**雙引號** `"`，失敗版本把單引號 `'`（ASCII 39）也轉成了 `` ` ``，例如 `it's` 會變成 `` it`s ``。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int sin=0, pur=0;
	string s="";
	while(getline(cin ,s)){
		for (char c : s){
			if (int(c) == 34){
				if(pur%2==0){
					cout << "``";
				}else{
					cout << "''";
				}
				pur++;
			}else{
				cout << c;
			}
		}
		cout << endl;
	}
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 只處理雙引號：用計數器 `pur` 判斷奇偶，第奇數個換成 ``` `` ```、第偶數個換成 `''`。計數器宣告在迴圈外，跨行時仍正確。
- AI 建議：變數名 `sin` 與標準函式 `std::sin` 同名，雖然能編譯但容易混淆；`main` 結尾也建議補上 `return 0;`。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | "To be or not to be," quoth the Bard, "that<br>is the question". | ``To be or not to be,'' quoth the Bard, ``that<br>is the question''. | ``To be or not to be,'' quoth the Bard, ``that<br>is the question''. | 題目範例（引號跨行） |
| Edge (fail code) | it's "ok" | it's ``ok'' | it`s ``ok'' | 含單引號 |
| Edge | it's "ok" | it's ``ok'' | it's ``ok'' | 含單引號 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同時轉換單、雙引號 | 只轉雙引號 |
| Edge Cases | 單引號被改掉 | 保留 |
| Output Handling | 同 | 同 |
| Complexity | O(n) | O(n) |
| Code Quality | 多餘的 sin 計數器 | （仍保留未使用） |

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
| UVa 272 / TeX Quotes | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
