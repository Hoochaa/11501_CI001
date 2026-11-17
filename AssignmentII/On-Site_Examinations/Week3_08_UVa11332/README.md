# Code Review Report: UVa 11332 - Summing Digits

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11332
- **Problem Title:** Summing Digits
- **Problem Link:** https://onlinejudge.org/external/113/11332.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-09-22）
- **Source Code (Initial/Fail):** [src/UVa11332_fail.cpp](./src/UVa11332_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa11332_ac.cpp](./src/UVa11332_ac.cpp)
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
	while(cin >> n){
		int ans=0;
		while(true){
			ans += n%10;
			if (n==ans){break;}
			n = n/10;
			if(n==0){n=ans; ans=0;}
		}
		cout << ans << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 沒有處理輸入結束條件：題目以 `0` 結尾，`0` 不應該輸出。失敗版本用 `while(cin >> n)`，讀到 0 時會多印一行 `0`。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	while(cin >> n && n!=0){
		int ans=0;
		while(true){
			ans += n%10;
			if (n==ans){break;}
			n = n/10;
			if(n==0){n=ans; ans=0;}
		}
		cout << ans << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 改成 `while(cin >> n && n!=0)`，讀到 0 就停止。
- 數位和的迴圈：每次把個位數加進 ans，數字變 0 時把 ans 當成新的 n 重來，直到只剩一位數。
- AI 建議：這題也可用數學性質 `g(n) = 1 + (n-1) % 9` 直接算出。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal (fail code) | 2<br>11<br>47<br>0 | 2<br>2 | 2<br>2<br>2<br>0 | 失敗版本多輸出了 0 |
| Normal | 12345<br>0 | 6 | 6 | 範例 |
| Boundary | 2000000000<br>0 | 2 | 2 | n 上限 |
| Edge | 7<br>0 | 7 | 7 | 個位數 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 未處理結尾 0 | 讀到 0 即停止 |
| Output Handling | 多一行輸出 | 正確 |
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
| UVa 11332 / Summing Digits | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
