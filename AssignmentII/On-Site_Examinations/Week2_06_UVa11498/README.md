# Code Review Report: UVa 11498 - Division of Nlogonia

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11498
- **Problem Title:** Division of Nlogonia
- **Problem Link:** https://onlinejudge.org/external/114/11498.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-09-15）
- **Source Code (Initial/Fail):** [src/UVa11498_fail.cpp](./src/UVa11498_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa11498_ac.cpp](./src/UVa11498_ac.cpp)
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
	int n=0;
	while(cin>>n){
		if(n==0){
			break;
		}
		if (n!=0){
		int dx=0, dy=0;
		cin >> dx >> dy;
		for (int i=0; i<n; i++){
			int x=0, y=0;
			cin >> x >> y;
			if(dx==x or dy==y){
				cout << "dicisa" << endl;
			}else if(dx<x && dy<y){
				cout << "NE" << endl;
			}else if(dx>x && dy<y){
				cout << "NO" << endl;
			}else if(dx>x && dy>y){
				cout << "SO" << endl;
			}else{
				cout << "SE" << endl;
			}
			
		}
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 輸出字串拼錯：`"dicisa"`，正確是 `"divisa"`。邏輯完全正確，只差一個字母。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	while(cin>>n){
		if(n==0){
			break;
		}
		if (n!=0){
		int dx=0, dy=0;
		cin >> dx >> dy;
		for (int i=0; i<n; i++){
			int x=0, y=0;
			cin >> x >> y;
			if(dx==x or dy==y){
				cout << "divisa" << endl;
			}else if(dx<x && dy<y){
				cout << "NE" << endl;
			}else if(dx>x && dy<y){
				cout << "NO" << endl;
			}else if(dx>x && dy>y){
				cout << "SO" << endl;
			}else{
				cout << "SE" << endl;
			}
			
		}
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 修正拼字後 AC。
- AI 建議：輸出固定字串時，直接從題目複製貼上可避免這類錯誤。另外 `if (n!=0)` 在 `break` 之後是多餘的判斷。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 3<br>2 1<br>10 10<br>-10 1<br>0 33<br>0 | NE<br>divisa<br>NO | NE<br>divisa<br>NO | 題目範例 |
| Boundary | 1<br>0 0<br>5 -5 | SE | SE | 第四象限 |
| Edge | 1<br>0 0<br>-3 -3 | SO | SO | 第三象限 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 同 | 同 |
| Output Handling | 拼字錯誤 dicisa | divisa |
| Complexity | O(K) | O(K) |
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
| UVa 11498 / Division of Nlogonia | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
