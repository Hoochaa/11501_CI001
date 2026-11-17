# Code Review Report: UVa 10055 - Hashmat the Brave Warrior

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10055
- **Problem Title:** Hashmat the Brave Warrior
- **Problem Link:** https://onlinejudge.org/external/100/10055.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 8 次，2026-09-08）
- **Source Code (Initial/Fail):** [src/UVa10055_fail.cpp](./src/UVa10055_fail.cpp)（Compile Error）
- **Source Code (Final/Accepted):** [src/UVa10055_ac.cpp](./src/UVa10055_ac.cpp)
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
#include <iostream>
using namespace std;
int main(){
	int a=0, b=0;
	while (cin >> a >> b){
    	if(a>b){
        	cout << a-b << endl;
        }else{
        	cout << b-a << endl;
        }
    }
  	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 提交時語言選成 **C**，`#include <iostream>` 在 C 編譯器下不存在（OJ 錯誤訊息：`main.c: fatal error: iostream: No such file or directory`）。程式邏輯本身沒有問題。
- 同樣的 CE 連續出現 6 次，表示前幾次沒有先看 OJ 回傳的錯誤訊息就重送。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while (cin >> a >> b){
    	if(a>b){
        	cout << a-b << endl;
        }else{
        	cout << b-a << endl;
        }
    }
  	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 語言改選 C++ 後即可編譯；邏輯為輸出兩數差的絕對值。
- ⚠️ AI 額外檢查：題目數值上限為 2^32，超過 `int` 範圍。本 OJ 測資剛好沒有測到，但在 UVa 官方會 WA（見測試表 Boundary）。建議改用 `long long`。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 10 12<br>10 14<br>100 200 | 2<br>4<br>100 | 2<br>4<br>100 | 題目範例 |
| Boundary | 0 4294967295 | 4294967295 | （無輸出） | 數值超過 int 範圍 |
| Edge | 5 5 | 0 | 0 | 兩數相等 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 未處理 &gt; int 範圍 | 仍未處理 &gt; int 範圍 |
| Output Handling | 同 | 同 |
| Complexity | O(1)/筆 | O(1)/筆 |
| Code Quality | 語言設定錯誤 | 語言正確 |

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
| UVa 10055 / Hashmat the Brave Warrior | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
