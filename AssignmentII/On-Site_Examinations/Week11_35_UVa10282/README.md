# Code Review Report: UVa 10282 - Babelfish

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10282
- **Problem Title:** Babelfish
- **Problem Link:** https://onlinejudge.org/external/102/10282.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-11-17）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10282.cpp](./src/s1151536-UVa10282.cpp)
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

首次提交即為最終版本，沒有失敗紀錄。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	map<string, string> mp;
	string s="";
	while(getline(cin, s)){
		if(s=="")break;
		stringstream ss(s);
		string a="", b="";
		ss >> a >> b;
		mp[b] = a;
	}
	while(getline(cin, s)){
		if(mp[s] != ""){
			cout << mp[s] << endl;
		}else{
			cout << "eh" << endl;
		}
	}
	
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 用 `map<string,string>` 存「外文 → 英文」，讀到空行後開始查詢，查不到輸出 `eh`。首次提交即 AC。
- AI 建議：`mp[s]` 查不到時會自動插入一筆空字串，查詢多時 map 會一直變大；改用 `mp.find(s)` 或 `mp.count(s)` 比較好。資料量大（10 萬筆）時可改用 `unordered_map` 加速。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | dog ogday<br>cat atcay<br>pig igpay<br>froot ootfray<br>loops oopslay<br><br>atcay<br>ittenkay<br>oopslay | cat<br>eh<br>loops | cat<br>eh<br>loops | 題目範例 |
| Edge | a b<br><br>b<br>c | a<br>eh | a<br>eh | 只有一筆字典 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

首次提交即 AC，無失敗版本可比較。

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
| UVa 10282 / Babelfish | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
