# Code Review Report: UVa 458 - The Decoder

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 458
- **Problem Title:** The Decoder
- **Problem Link:** https://onlinejudge.org/external/4/458.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 7 次，2026-11-10）
- **Source Code (Initial/Fail):** [src/s1151536-UVa458_fail.cpp](./src/s1151536-UVa458_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa458.cpp](./src/s1151536-UVa458.cpp)（最新一次提交，尚未 AC）
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
	string s;
	while(getline(cin, s)){
		if(s==""){
			cout << endl;
			continue;
		}
		for (char c : s){
			cout << char((int(c)-7+127)%127);
		}
		cout << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 較早的版本用 `(c - 7 + 127) % 127`，這不是題目的規則（每個字元的 ASCII 值減 7 即可），會讓部分字元算錯。
- 最新版本改回 `c - 7`，AI 在本機與標準寫法（`getchar` 逐字元讀、遇到 `\n` 原樣輸出、其他字元減 7）比對，範例與多種輸入的結果**完全相同**，無法在本機重現 WA。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin, s)){
		if(s==""){
			cout << endl;
			continue;
		}
		for (char c : s){
			cout << char((int(c)-7));
		}
		cout << endl;
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** AI 推測的可能原因（需自行驗證，或向助教確認測資）：
   1. 測資若含 Windows 換行 `\r\n`，`\r` 也會被減 7 變成控制字元。
   2. `getline` + `endl` 會在最後一行補上換行，若評測對結尾換行嚴格，輸出會不同。
- 建議改用 `int c; while((c = getchar()) != EOF) putchar(c == '\n' ? c : c - 7);`，輸出與輸入逐位元組對應。作業三是 UVa 458 的延伸討論，可一併釐清。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5 | *CDC is the trademark of the Control Data Corporation. | *CDC is the trademark of the Control Data Corporation. | 題目範例 |
| Edge | 1JKJ（結尾沒有換行） | *CDC | *CDC＋換行 | 最後一行沒有換行 |
| Edge | 1JKJ'pz'\r\n | *CDC is  | *CDC is ＋控制字元 0x06 | Windows 換行 |

⚠️ 有 2 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | (c-7+127)%127 | c-7 |
| Edge Cases | — | \r、結尾換行未處理 |
| Output Handling | getline+endl | getline+endl |
| Complexity | O(n) | O(n) |
| Code Quality | 多次提交 | （待確認） |

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
| UVa 458 / The Decoder | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
