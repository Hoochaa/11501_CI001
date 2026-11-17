# Code Review Report: UVa 11547 - Automatic Answer

> Week 8 期中考（Midterm）題目

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11547
- **Problem Title:** Automatic Answer
- **Problem Link:** https://onlinejudge.org/external/115/11547.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 4 次，2026-10-27）
- **Source Code (Initial/Fail):** [src/s1151536-UVa11547_fail.cpp](./src/s1151536-UVa11547_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa11547.cpp](./src/s1151536-UVa11547.cpp)（最新一次提交，尚未 AC）
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
	int i=0;
	cin >> i;
	while(i--){
		long double n;
		cin >> n;
		n = (n * 0.4819277 + 4.13655);
		n = abs(int(n)%10);
		cout << n << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 公式化簡錯誤：題目是 `((n×567/9 + 7492)×235/47 − 498)` 再取十位數，程式卻用 `n×0.4819277 + 4.13655` 這個近似值，與原式不等價。範例剛好答對，`n = 0` 時就錯（應為 6，輸出 4）。
- 用 `long double` 做運算再轉 int，浮點誤差也可能讓十位數算錯；輸出時直接印 long double 也不保證格式。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int i=0;
	cin >> i;
	while(i--){
		long double n;
		cin >> n;
		
		n = (n * 0.4819277 + 4.13655);
		n = abs(int(n)%10);
		cout << n << endl;
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
- 全部用整數（`long long`）照題目順序計算：`v = (n*567/9 + 7492)*235/47 - 498`，答案是 `abs(v) / 10 % 10`。567/9 = 63、235/47 = 5 都能整除，不會有誤差。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 2<br>637<br>-120 | 1<br>3 | 1<br>3 | 題目範例 |
| Boundary | 1<br>1000 | 6 | 6 | n = 1000 |
| Edge | 1<br>0 | 6 | 4 | n = 0 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | 近似公式 | （待修正） |
| Edge Cases | n=0 等錯誤 | （待修正） |
| Output Handling | 輸出 long double | （待修正） |
| Complexity | O(1) | O(1) |
| Code Quality | 浮點運算 | （待修正） |

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
| UVa 11547 / Automatic Answer | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
