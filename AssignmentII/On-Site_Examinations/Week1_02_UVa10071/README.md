# Code Review Report: UVa 10071 - Back to High School Physics

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10071
- **Problem Title:** Back to High School Physics
- **Problem Link:** https://onlinejudge.org/external/100/10071.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-09-08）
- **Source Code (Initial/Fail):** [src/UVa10071_fail.cpp](./src/UVa10071_fail.cpp)（Compile Error）
- **Source Code (Final/Accepted):** [src/UVa10071_ac.cpp](./src/UVa10071_ac.cpp)
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
#include <nits/stdc++.h>
using namespace std;
int main(){
  	long long v=0, t=0;
  	while(cin >> v >> t){
    	cout << v*2*t << endl;
    }
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 標頭檔打錯字：`#include <nits/stdc++.h>`（應為 `bits`）。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
  	long long v=0, t=0;
  	while(cin >> v >> t){
    	cout << v*2*t << endl;
    }
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 修正標頭檔後，直接輸出位移 `2*v*t`，使用 `long long` 也避免了溢位。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 0 0<br>5 12 | 0<br>120 | 0<br>120 | 題目範例 |
| Boundary | 100 200 | 40000 | 40000 | v、t 上限 |
| Edge | -100 200 | -40000 | -40000 | 速度為負 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 同 | 同 |
| Output Handling | 同 | 同 |
| Complexity | O(1)/筆 | O(1)/筆 |
| Code Quality | 打字錯誤 | 已修正 |

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
| UVa 10071 / Back to High School Physics | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
