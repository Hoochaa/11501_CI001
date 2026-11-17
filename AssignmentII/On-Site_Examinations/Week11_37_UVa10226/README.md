# Code Review Report: UVa 10226 - Hardwood Species

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10226
- **Problem Title:** Hardwood Species
- **Problem Link:** https://onlinejudge.org/external/102/10226.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 3 次，2026-11-17）
- **Source Code (Initial/Fail):** [src/s1151536-UVa10226_fail.cpp](./src/s1151536-UVa10226_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10226.cpp](./src/s1151536-UVa10226.cpp)（最新一次提交，尚未 AC）
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
	int n=0;
	cin >> n;
	cin.ignore();
	string s="";
	while(n--){
		map<string, float> mp;
		int num=0;
		while(getline(cin, s) && s!=""){
			if(!mp[s])mp[s] = 0;
			mp[s]++;
			num++;
		}
		for (auto a : mp){
			cout << fixed << setprecision(4) << a.first << " " << a.second/num*100.0 << endl;
		}
		cout << endl;
		return 0;
	}

}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 失敗版本在 `while(n--)` 迴圈裡寫了 `return 0;`，只處理第一組資料就結束。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=0;
	cin >> n;
	cin.ignore();
	string s="";
	while(n--){
		map<string, float> mp;
		int num=0;
		while(getline(cin, s) && s!=""){
			if(!mp[s])mp[s] = 0;
			mp[s]++;
			num++;
		}
		for (auto a : mp){
			cout << fixed << setprecision(4) << a.first << " " << a.second/num*100.0 << endl;
		}
		if(n!=0)cout << endl;
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 最新版本移除了 `return 0`，但還有一個關鍵錯誤：
- **輸入格式**：測資數量那一行之後緊接著一個**空行**，才開始第一組樹名。`cin.ignore()` 只吃掉換行，第一次 `getline` 讀到的就是那個空行，迴圈立刻結束，`num = 0`，什麼都沒輸出（AI 用題目範例實測，輸出為空）。
- 修正方向（AI 建議，請自行實作後重新提交）：讀完 n 之後再多 `getline` 一次把空行吃掉；百分比用 `double` 計算（float 精度只有約 7 位）。
- `if(!mp[s]) mp[s] = 0;` 是多餘的，`mp[s]++` 會自動從 0 開始。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 1<br>（空行）<br>Red Alder<br>Ash<br>…（題目範例共 29 行） | Ash 13.7931<br>Aspen 3.4483<br>… | （無輸出） | 題目範例，數量後有空行 |
| Edge | 1<br>Ash<br>Oak | Ash 50.0000<br>Oak 50.0000 | Ash 50.0000<br>Oak 50.0000 | 沒有空行時邏輯本身正確 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | 迴圈內 return 0 | 已移除 |
| Edge Cases | 開頭空行未處理 | 仍未處理 |
| Output Handling | 同 | 同 |
| Complexity | O(N log K) | O(N log K) |
| Code Quality | float 精度 | （建議改 double） |

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
| UVa 10226 / Hardwood Species | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
