# Code Review Report: UVa 1225 - Digit Counting

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 1225
- **Problem Title:** Digit Counting
- **Problem Link:** https://onlinejudge.org/external/12/1225.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 2 次，2026-09-22）
- **Source Code (Initial/Fail):** [src/UVa1225_fail.cpp](./src/UVa1225_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa1225_ac.cpp](./src/UVa1225_ac.cpp)
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
	int a=0, b=0;
	while(cin >> a >>  b){
		if (a==0 && b==0){break;}
		int ans=0;
		while(a!=0&&b!=0){
			ans += (a%10+b%10)/10;
			a /= 10;
			b /= 10;
		}
		if (ans==0){
			cout << "No carry operation." << endl;
		}else{
			cout << ans << " carry operation." << endl;
		}
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 第一次提交的程式碼其實是 **UVa 10035（Primary Arithmetic）** 的程式，交錯題目了。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	vector<int> vec;
	while(n--){
		vec.assign(10, 0);
		int num=0;
		cin >> num;
		for (int i=0; i<=num; i++){
			int k=i;
			while(k != 0){
			int p=k%10;
			vec[p] += 1;
			k = k/10;
			}
		}
		for (int i=0; i<10; i++){
			cout << vec[i];
			if(i!=9){
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 對 1..N 每個數拆出各位數字並計數，輸出 0~9 的次數，數字間以空白分隔、行尾無多餘空白。
- N ≤ 10000，O(N log N) 足夠。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 2<br>3<br>13 | 0 1 1 1 0 0 0 0 0 0<br>1 6 2 2 1 1 1 1 1 1 | 0 1 1 1 0 0 0 0 0 0<br>1 6 2 2 1 1 1 1 1 1 | 題目範例 |
| Boundary | 1<br>1 | 0 1 0 0 0 0 0 0 0 0 | 0 1 0 0 0 0 0 0 0 0 | N = 1 |
| Edge | 1<br>10000 | 2893 4001 4000 4000 4000 4000 4000 4000 4000 4000 | 2893 4001 4000 4000 4000 4000 4000 4000 4000 4000 | N = 10000 上限 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 交錯題目 | 正確演算法 |
| Edge Cases | — | 有處理 N 上限 |
| Output Handling | — | 行尾無空白 |
| Complexity | — | O(N log N) |
| Code Quality | 提交前未確認題號 | 正確 |

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
| UVa 1225 / Digit Counting | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
