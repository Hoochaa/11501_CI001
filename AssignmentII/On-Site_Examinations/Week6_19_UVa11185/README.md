# Code Review Report: UVa 11185 - Ternary

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11185
- **Problem Title:** Ternary
- **Problem Link:** https://onlinejudge.org/external/111/11185.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 12 次，2026-10-13）
- **Source Code (Initial/Fail):** [src/UVa11185_fail.cpp](./src/UVa11185_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa11185_latest.cpp](./src/UVa11185_latest.cpp)（最新一次提交，尚未 AC）
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
	long long n=0;
	while(cin >> n && n>=0 && n<1000000001){
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		long long p=log(n)/log(3);
		while(p>=0){
			long long num = pow(3, p);
			cout << (n/num);
			n = n%num;
			p--;
		}
		cout << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 用 `log(n)/log(3)` 求最高位數，浮點誤差會讓 3 的次方算錯：`log(243)/log(3)` 實際算出 4.9999…，轉成整數變 4，於是 243 被輸出成 `30000`（正確為 `100000`）。
- 最後兩次提交的程式碼完全相同，重送前沒有找出新的錯誤原因。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n=0;
	while(cin >> n && n>=0 && n<1000000001){
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		long long p=log(n)/log(3);
		while(p>=0){
			long long num = pow(3, p);
			cout << (n/num);
			n = n%num;
			p--;
		}
		cout << endl;
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
- 改用整數運算：反覆 `n % 3` 取得每一位、`n /= 3`，把餘數存進字串後反轉輸出；n = 0 時輸出 0。完全不需要 `log` 與 `pow`。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 1<br>4<br>10<br>-1 | 1<br>11<br>101 | 1<br>11<br>101 | 題目範例 |
| Edge | 243<br>-1 | 100000 | 30000 | 3^5，log 浮點誤差 |
| Edge | 59049<br>-1 | 10000000000 | 3000000000 | 3^10 |
| Edge | 14348907<br>-1 | 1000000000000000 | 300000000000000 | 3^15 |

⚠️ 有 3 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | log/pow 浮點計算位數 | （待修正） |
| Edge Cases | 3 的次方出錯 | （待修正） |
| Output Handling | 同 | （待修正） |
| Complexity | O(log n) | O(log n) |
| Code Quality | 重複提交相同程式 | （待修正） |

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
| UVa 11185 / Ternary | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
