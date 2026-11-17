# Code Review Report: UVa 10035 - Primary Arithmetic

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10035
- **Problem Title:** Primary Arithmetic
- **Problem Link:** https://onlinejudge.org/external/100/10035.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 3 次，2026-09-22）
- **Source Code (Initial/Fail):** [src/s1151536-UVa10035_fail.cpp](./src/s1151536-UVa10035_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10035.cpp](./src/s1151536-UVa10035.cpp)
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
	int a=0, b=0;
	while(cin >> a >>  b){
		if (a==0 && b==0){break;}
		int ans=0;
		while(a!=0 && b!=0){
			ans += (a%10 + b%10)/10;
			a /= 10;
			b /= 10;
		}
		if (ans==0){
			cout << "No carry operation." << endl;
		}else{
			cout << ans << " carry operation." << endl;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 輸出格式：進位次數大於 1 時要用複數 `carry operations.`，失敗版本一律輸出單數。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while(cin >> a >>  b){
		if (a==0 && b==0){break;}
		int ans=0;
		while(a!=0&&b!=0){
			ans += (a%10+b%10)/10;
			a /= 10;
			b /= 10;
		}
		if (ans==0){
			cout << "No carry operation." << endl;
		}else if (ans == 1){
			cout << ans << " carry operation." << endl;
		}else{
			cout << ans << " carry operations." << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 加上 `ans == 1` 與其他情況的分支後 AC。
- ⚠️ AI 額外檢查（本 OJ 測資沒測到）：
   1. 沒有把「進位」帶到下一位：`(a%10 + b%10)/10` 只看兩個數字本身，`19 + 81` 的十位數應該是 1+8+1=10 也要進位。
   2. `while(a!=0 && b!=0)` 在較短的數用完時就停止，`999 + 1` 的進位會一路傳到最高位，正確答案是 3 次，程式輸出 1 次。
- 修正方向：用一個 `carry` 變數記錄進位，迴圈條件改成 `a!=0 || b!=0`，每位計算 `a%10 + b%10 + carry`。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 123 456<br>555 555<br>123 594<br>0 0 | No carry operation.<br>3 carry operations.<br>1 carry operation. | No carry operation.<br>3 carry operations.<br>1 carry operation. | 題目範例 |
| Edge | 999 1<br>0 0 | 3 carry operations. | 1 carry operation. | 進位傳遞到較長的數 |
| Edge | 19 81<br>0 0 | 2 carry operations. | 1 carry operation. | 前一位進位造成下一位進位 |

⚠️ 有 2 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同（未傳遞進位） | 同（未傳遞進位） |
| Edge Cases | 未處理連續進位 | 仍未處理 |
| Output Handling | 單複數錯誤 | 單複數正確 |
| Complexity | O(位數) | O(位數) |
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
| UVa 10035 / Primary Arithmetic | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
