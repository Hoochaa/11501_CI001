# Code Review Report: UVa 11461 - Square Numbers

> Week 8 期中考（Midterm）題目

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11461
- **Problem Title:** Square Numbers
- **Problem Link:** https://onlinejudge.org/external/114/11461.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 7 次，2026-10-27）
- **Source Code (Initial/Fail):** [src/UVa11461_fail.cpp](./src/UVa11461_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa11461_ac.cpp](./src/UVa11461_ac.cpp)
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
	int l=0, r=0, buf=1;
	vector<int> vec;
	vec.assign(100001, 0);
	for(int i=1; i<int(pow(100000, 0.5)); i++){
		vec[i*i] = 1;
	}
	
	while(cin >> l >> r){
		int ans =0;
		if(l==0 && r==0)break;
		for (int i=l; i<r+1; i++){
			ans += vec[i];
		}
		cout << ans << endl;
	}
	
	/*
	for(int i=1; i<100002; i++){
		vec[i] = vec[i-1] + vec[i];
		cout << vec[i] << " ";
	}
	cout << endl;
	int ans=0;
	while(cin >> l >> r){
		if(l==0 && r==0) break;
		if(l==0)l=1;
		ans = vec[r] - vec[l-1];
		cout << ans << endl;
	}
	*/
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 建表的迴圈邊界少了一個：`i < int(pow(100000, 0.5))` 只到 315，漏掉 316² = 99856。查詢區間包含 99856 時少算 1。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int l=0, r=0, buf=1;
	vector<int> vec;
	vec.assign(100001, 0);
	for(int i=1; i<int(pow(100000, 0.5))+1; i++){
		vec[i*i] = 1;
	}
	
	while(cin >> l >> r){
		int ans =0;
		if(l==0 && r==0)break;
		for (int i=l; i<r+1; i++){
			ans += vec[i];
		}
		cout << ans << endl;
	}
	
	/*
	for(int i=1; i<100002; i++){
		vec[i] = vec[i-1] + vec[i];
		cout << vec[i] << " ";
	}
	cout << endl;
	int ans=0;
	while(cin >> l >> r){
		if(l==0 && r==0) break;
		if(l==0)l=1;
		ans = vec[r] - vec[l-1];
		cout << ans << endl;
	}
	*/
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 改成 `i < int(pow(100000,0.5)) + 1`，把 316² 也標記進表後 AC。
- AI 建議：程式中被註解掉的前綴和寫法（`vec[i] += vec[i-1]`，查詢 `vec[r] - vec[l-1]`）是更好的 O(1) 查詢方法，可以再試著修好它。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Boundary (fail code) | 99856 99856<br>0 0 | 1 | 0 | 316² 是範圍內最大平方數 |
| Normal | 1 4<br>1 10<br>0 0 | 2<br>3 | 2<br>3 | 題目範例 |
| Boundary | 99856 99856<br>0 0 | 1 | 1 | 316² |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 同 | 同 |
| Edge Cases | 少標記 316² | 已包含 |
| Output Handling | 同 | 同 |
| Complexity | O(b−a)/查詢 | O(b−a)/查詢 |
| Code Quality | 迴圈邊界 off-by-one | 已修正 |

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
| UVa 11461 / Square Numbers | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
