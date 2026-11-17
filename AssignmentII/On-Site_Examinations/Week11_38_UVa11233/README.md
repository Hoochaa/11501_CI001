# Code Review Report: UVa 11233 - Deli Deli

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11233
- **Problem Title:** Deli Deli
- **Problem Link:** https://onlinejudge.org/external/112/11233.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 3 次，2026-11-17）
- **Source Code (Initial/Fail):** [src/s1151536-UVa11233_fail.cpp](./src/s1151536-UVa11233_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa11233.cpp](./src/s1151536-UVa11233.cpp)
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
	int a, b;
	cin >> a >> b;
	map<string, string> mp;
	while(a--){
		string sa, sb;
		cin >> sa >> sb;
		mp[sa] = sb;
	}
	while(b--){
		string s;
		cin >> s;
		if(mp[s]!=""){
			cout << mp[s] << endl;
		}else if (s[s.size()-1] == 'y'){
			s[s.size()-1] = 'i';
			cout << s << "es" << endl;
		}else if (s[s.size()-1] == 'o' || s[s.size()-1] == 's' || s[s.size()-1] == 'x'){
			cout << s << "es" << endl;
		}else if(s[s.size()-1]=='h' && (s[s.size()-2] == 's' || s[s.size()-2] == 'c')){
			cout << s << "es" << endl;
		}else{
			cout << s << "s" << endl;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 規則「子音 + y 結尾 → 改成 ies」漏了「子音」的條件：失敗版本只要結尾是 y 就改，`boy` 會變成 `boies`（應為 `boys`）。
- 第一次提交還把 `'x'` 打成重複的 `'s'`，`box` 會變成 `boxs`。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	map<string, string> mp;
	while(a--){
		string sa, sb;
		cin >> sa >> sb;
		mp[sa] = sb;
	}
	while(b--){
		string s;
		cin >> s;
		if(mp[s]!=""){
			cout << mp[s] << endl;
		}else if (s[s.size()-1] == 'y' && s[s.size()-2] != 'u' && s[s.size()-2] != 'a' && s[s.size()-2] != 'e' && s[s.size()-2] != 'i' && s[s.size()-2] != 'o'){
			s[s.size()-1] = 'i';
			cout << s << "es" << endl;
		}else if (s[s.size()-1] == 'o' || s[s.size()-1] == 's' || s[s.size()-1] == 'x'){
			cout << s << "es" << endl;
		}else if(s[s.size()-1]=='h' && (s[s.size()-2] == 's' || s[s.size()-2] == 'c')){
			cout << s << "es" << endl;
		}else{
			cout << s << "s" << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 加上「倒數第二個字母不是母音 a/e/i/o/u」的條件後 AC。
- ⚠️ AI 額外檢查：`s[s.size()-2]` 在單字只有 1 個字母時會存取到字串範圍外（未定義行為），例如輸入 `h` 或 `y`。本 OJ 測資沒測到，建議先判斷 `s.size() >= 2`。
- 另外 `mp[s]` 查不到時會插入空字串，可改用 `mp.count(s)`。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 3 3<br>rice rice<br>spaghetti spaghetti<br>octopus octopi<br>rice<br>lobster<br>spaghetti | rice<br>lobsters<br>spaghetti | rice<br>lobsters<br>spaghetti | 不規則字典＋一般規則 |
| Edge | 0 4<br>boy<br>lady<br>box<br>church | boys<br>ladies<br>boxes<br>churches | boys<br>ladies<br>boxes<br>churches | 各條規則 |
| Edge (fail code) | 0 2<br>boy<br>lady | boys<br>ladies | boies<br>ladies | 母音 + y |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | y 結尾一律改 ies | 檢查前一字母是否為子音 |
| Edge Cases | 母音+y 錯誤 | 正確 |
| Output Handling | 同 | 同 |
| Complexity | O(Q log N) | O(Q log N) |
| Code Quality | 單字母越界（同） | 單字母越界（同） |

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
| UVa 11233 / Deli Deli | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
