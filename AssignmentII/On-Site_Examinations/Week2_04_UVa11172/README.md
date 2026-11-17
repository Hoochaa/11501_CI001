# Code Review Report: UVa 11172 - Relational Operators

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11172
- **Problem Title:** Relational Operators
- **Problem Link:** https://onlinejudge.org/external/111/11172.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-09-15）
- **Source Code (Initial/Fail):** [src/UVa11172_fail.cpp](./src/UVa11172_fail.cpp)（Compile Error）
- **Source Code (Final/Accepted):** [src/UVa11172_ac.cpp](./src/UVa11172_ac.cpp)
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
	int n = 0;
	cin >> n;
	for (int i=0; i<n; i++){
		int a=0, b=0;
		cin >> a >> b;
		if(a > b){
			cout << ">" << endl;
		}else if(a<b){
			cout << "<" << endl;
		}else{
			cout << "=" << endl;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 與 Week 1 相同：語言選成 **C**，`bits/stdc++.h` 不存在（OJ 錯誤訊息：`main.c: fatal error: bits/stdc++.h: No such file or directory`）。程式碼完全相同。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 0;
	cin >> n;
	for (int i=0; i<n; i++){
		int a=0, b=0;
		cin >> a >> b;
		if(a > b){
			cout << ">" << endl;
		}else if(a<b){
			cout << "<" << endl;
		}else{
			cout << "=" << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 改選 C++ 後 AC。題目數值在 int 範圍內，三種比較分支完整。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 3<br>10 20<br>20 10<br>10 10 | &lt;<br>&gt;<br>= | &lt;<br>&gt;<br>= | 題目範例 |
| Boundary | 1<br>-1000000001 1000000001 | &lt; | &lt; | 大數值 |
| Edge | 1<br>-5 -5 | = | = | 負數相等 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 同 | 同 |
| Output Handling | 同 | 同 |
| Complexity | O(1)/筆 | O(1)/筆 |
| Code Quality | 語言設定錯誤（第二次） | 語言正確 |

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
| UVa 11172 / Relational Operators | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
