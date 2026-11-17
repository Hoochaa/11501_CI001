# Code Review Report: UVa 10346 - Peter's Smokes

> Week 8 期中考（Midterm）題目

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10346
- **Problem Title:** Peter's Smokes
- **Problem Link:** https://onlinejudge.org/external/103/10346.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 3 次，2026-10-27）
- **Source Code (Initial/Fail):** [src/s1151536-UVa10346_fail.cpp](./src/s1151536-UVa10346_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10346.cpp](./src/s1151536-UVa10346.cpp)
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
int n=0, k=0;
int main(){
	while(cin >> n >> k){
		if(n==0 || n==1){
			cout << n << endl;
			continue;	
		}
		int buts=0, ans=0;
		while(true){
			ans += n;
			buts += n;
			if(buts<k && n==0)break;
			n=buts/k;
			buts = buts%k;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 計算完 `ans` 後沒有 `cout`，一般情況完全沒有輸出。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int n=0, k=0;
int main(){
	while(cin >> n >> k){
		if(n==0 || n==1){
			cout << n << endl;
			continue;	
		}
		int buts=0, ans=0;
		while(true){
			ans += n;
			buts += n;
			if(buts<k && n==0)break;
			n=buts/k;
			buts = buts%k;
		}
		cout << ans << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 補上 `cout << ans << endl;` 後 AC。模擬：抽完的菸蒂累積起來，每 k 個換一根，直到菸蒂不足且手上沒菸。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 4 3<br>10 3<br>100 5 | 5<br>14<br>124 | 5<br>14<br>124 | 題目範例 |
| Edge | 1 2 | 1 | 1 | 只有一根 |
| Boundary | 5 2 | 9 | 9 | k = 2，多輪兌換 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 同 | 同 |
| Output Handling | 缺少輸出 | 有輸出 |
| Complexity | O(log n) | O(log n) |
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
| UVa 10346 / Peter's Smokes | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
