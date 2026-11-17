# Code Review Report: UVa 10008 - What's Cryptanalysis?

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10008
- **Problem Title:** What's Cryptanalysis?
- **Problem Link:** https://onlinejudge.org/external/100/10008.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-11-03）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10008.cpp](./src/s1151536-UVa10008.cpp)
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
	vector<vector<int>> vec;
	vector<int> buf;
	buf.assign(2, 0);
	vec.assign(26, buf);
	for (int i=25; i>=0; i--){
		vec[25-i][1] = i;
	}
	int n=0;
	cin >> n;
	cin.ignore();
	string s="";
	while(n--){
		getline(cin, s);
		if(s=="")continue;
		for (char c : s){
			if((int('a')<=int(c) && int('z')>=int(c)) || (int('A')<=int(c) && int('Z')>=int(c))){
				c = toupper(c);
				vec[int(c)-int('A')][0] += 1;
			}
		}
	}
	sort(vec.begin(), vec.end());
	for (int i=25; i>=0; i--){
		if(vec[i][0]>0){
			cout << char(abs(vec[i][1]-25)+int('A')) << " " << vec[i][0] << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 統計 26 個字母（不分大小寫）的出現次數，依次數遞減、次數相同時依字母遞增輸出。首次提交即 AC。
- 技巧：每個元素存成 `{次數, 25-字母序}`，遞增排序後從後往前印，就同時達成「次數大的先、同次數字母小的先」。這個寫法正確但不直覺。
- AI 建議：可用 `vector<pair<int,char>>` 搭配自訂比較函式 `sort`，可讀性更高；判斷字母可用 `isalpha`。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 3<br>This is a test.<br>Count me 1 2 3 4 5.<br>Wow!!!! Is this question easy? | S 7<br>T 6<br>I 5<br>E 4<br>O 3<br>A 2<br>H 2<br>N 2<br>U 2<br>W 2<br>C 1<br>M 1<br>Q 1<br>Y 1 | （與預期相同） | 題目範例 |
| Edge | 1<br>aAbB | A 2<br>B 2 | A 2<br>B 2 | 大小寫合併、同次數依字母排序 |

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
| UVa 10008 / What's Cryptanalysis? | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
