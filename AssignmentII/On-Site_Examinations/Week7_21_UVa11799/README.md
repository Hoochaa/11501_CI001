# Code Review Report: UVa 11799 - Horror Dash

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11799
- **Problem Title:** Horror Dash
- **Problem Link:** https://onlinejudge.org/external/117/11799.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-10-20）
- **Source Code (Initial/Fail):** [src/s1151536-UVa11799_fail.cpp](./src/s1151536-UVa11799_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa11799.cpp](./src/s1151536-UVa11799.cpp)
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
	int n=0, cnt=0;
	cin >> n;
	cin.ignore();
	while(n--){
		cnt++;
		string s="";
		getline(cin, s);
		stringstream ss(s);
		int num=0, maxium=0;
		while(ss >> num){
			maxium = max(maxium, num);
		}
		cout << "case " << cnt << ": " << maxium << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 輸出大小寫錯誤：`"case "` 應為 `"Case "`。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0, cnt=0;
	cin >> n;
	cin.ignore();
	while(n--){
		cnt++;
		string s="";
		getline(cin, s);
		stringstream ss(s);
		int num=0, maxium=0;
		while(ss >> num){
			maxium = max(maxium, num);
		}
		cout << "Case " << cnt << ": " << maxium << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 修正大小寫後 AC。用 `getline` + `stringstream` 讀一整行，取最大值。
- AI 建議：每行第一個數是學生人數 N，其實也可以 `cin >> N` 後讀 N 個數，就不需要 `cin.ignore()` 與 stringstream；目前寫法把 N 也拿去比最大值，剛好不影響答案，但要知道這件事。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 2<br>5 9 3 5 2 6<br>1 2 | Case 1: 9<br>Case 2: 2 | Case 1: 9<br>Case 2: 2 | 題目範例 |
| Edge | 1<br>1 10000 | Case 1: 10000 | Case 1: 10000 | 只有一位學生 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 同 | 同 |
| Output Handling | case 小寫 | Case |
| Complexity | O(N) | O(N) |
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
| UVa 11799 / Horror Dash | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
