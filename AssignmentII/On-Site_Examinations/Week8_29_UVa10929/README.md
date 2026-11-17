# Code Review Report: UVa 10929 - You can say 11

> Week 8 期中考（Midterm）題目

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10929
- **Problem Title:** You can say 11
- **Problem Link:** https://onlinejudge.org/external/109/10929.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-10-27）
- **Source Code (Initial/Fail):** [src/UVa10929_fail.cpp](./src/UVa10929_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa10929_ac.cpp](./src/UVa10929_ac.cpp)
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
	long long s=0;
	while(cin >> s && s!=0){
		if(s%11 == 0 && s>=11){
			cout << s << " is a multiple of 11." << endl;
		}else{
			cout << s << " is not a multiple of 11." << endl;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 數字最多 1000 位，`long long` 只能存約 19 位，長數字讀取失敗。
- 另外 `s >= 11` 的條件多餘。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	//1=49
	while(cin >> s && s!="0"){
		int l=0, r=0;
		for (int i=0; i<s.size(); i++){
			int num = int(s[i])-48;
			if(i%2==0){
				l += num;
			}else{
				r += num;
			}
		}
		if(abs(l-r)%11==0){
			cout << s << " is a multiple of 11." << endl;
		}else{
			cout << s << " is not a multiple of 11." << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 用 `string` 讀入，利用 11 的倍數判別法：奇數位和與偶數位和的差是 11 的倍數。
- 輸出時直接印原字串，保留原本的寫法。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Edge (fail code) | 112233445566778899001122<br>0 | 112233445566778899001122 is a multiple of 11. | （無輸出） | 超過 long long |
| Normal | 112233<br>30800<br>2937<br>323455693<br>5038297<br>112234<br>0 | 112233 is a multiple of 11.<br>30800 is a multiple of 11.<br>2937 is a multiple of 11.<br>323455693 is a multiple of 11.<br>5038297 is a multiple of 11.<br>112234 is not a multiple of 11. | （與預期相同） | 題目範例 |
| Edge | 112233445566778899001122<br>0 | 112233445566778899001122 is a multiple of 11. | 112233445566778899001122 is a multiple of 11. | 超長數字 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 整數取餘數 | 11 倍數判別法 |
| Edge Cases | 超過 long long | 字串處理任意長度 |
| Output Handling | 同 | 同 |
| Complexity | O(1) | O(位數) |
| Code Quality | 多餘條件 | 簡潔 |

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
| UVa 10929 / You can say 11 | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
