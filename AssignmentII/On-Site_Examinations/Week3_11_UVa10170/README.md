# Code Review Report: UVa 10170 - The Hotel with Infinite Rooms

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10170
- **Problem Title:** The Hotel with Infinite Rooms
- **Problem Link:** https://onlinejudge.org/external/101/10170.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 3 次，2026-09-22）
- **Source Code (Initial/Fail):** [src/s1151536-UVa10170_fail.cpp](./src/s1151536-UVa10170_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10170.cpp](./src/s1151536-UVa10170.cpp)
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
	while(cin >> a >> b){
		a--;
		while(b>0){
			a++;
			b -= a;
		}
		cout << a << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- D 最大可到 10^15，失敗版本用 `int b` 讀入，超過 int 範圍，`cin` 讀取失敗，程式沒有任何輸出。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0;
	long long b=0;
	while(cin >> a >> b){
		a--;
		while(b>0){
			a++;
			b -= a;
		}
		cout << a << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 把 `b` 改成 `long long` 後 AC。
- 模擬：每團人數從 S 開始逐次加 1，把天數 D 逐團扣掉，扣到 ≤ 0 時的那團就是答案。
- AI 建議：最多約 4.5×10^7 次迴圈；若想更快，可用等差數列公式加二分搜尋。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 1 6<br>3 10<br>3 14 | 3<br>5<br>6 | 3<br>5<br>6 | 題目範例 |
| Boundary (fail code) | 1 1000000000000000 | 44721360 | （無輸出） | D = 10^15 超過 int |
| Boundary | 1 1000000000000000 | 44721360 | 44721360 | D = 10^15 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | D 溢位 | long long |
| Output Handling | 同 | 同 |
| Complexity | O(√D) | O(√D) |
| Code Quality | 型別選擇錯誤 | 型別正確 |

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
| UVa 10170 / The Hotel with Infinite Rooms | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
