# Code Review Report: UVa 496 - Simply Subsets

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 496
- **Problem Title:** Simply Subsets
- **Problem Link:** https://onlinejudge.org/external/4/496.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-11-17）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/s1151536-UVa496.cpp](./src/s1151536-UVa496.cpp)
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
	string s;
	while(getline(cin, s)){
		vector<int> A;
		vector<int> B;
		stringstream ss(s);
		int i=0;
		while(ss >> i){
			A.push_back(i);
		}
		getline(cin, s);
		stringstream sss(s);
		while(sss >> i){
			B.push_back(i);
		}
		vector<int> a;
		bool check=false;
		if (A.size()<B.size()){
			check = true;
			a = A;
			A = B;
			B = a;
		}else{
			a = B;
		}
		
		int ct = 0;
		for(int j : a){
			for(int k : A){
				if(j==k){
					ct++;
				}
			}
		}
		
		if(ct==0){
			cout << "A and B are disjoint" << endl;
		}else if(A.size() == a.size() && ct == A.size()){
			cout << "A equals B" << endl;
		}else if(a.size() < A.size() && !check && ct == a.size()){
			cout << "B is a proper subset of A" << endl;
		}else if(a.size() < A.size() && check && ct == a.size()){
			cout << "A is a proper subset of B" << endl;
		}else{
			cout << "I'm confused!" << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 讀入兩行集合，計算共同元素個數 ct，再依 ct 與兩集合大小判斷五種關係。首次提交即 AC。
- AI 建議：用 `set<int>` 搭配 `count` 會更清楚，也能避免雙層迴圈 O(|A||B|)；目前寫法依賴「同一集合內元素不重複」的題目保證。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 55 27<br>55 27<br>9 24 1995<br>9 24<br>1 2 3<br>1 2 3 4<br>1 2 3<br>4 5 6<br>1 2<br>2 3 | A equals B<br>B is a proper subset of A<br>A is a proper subset of B<br>A and B are disjoint<br>I'm confused! | A equals B<br>B is a proper subset of A<br>A is a proper subset of B<br>A and B are disjoint<br>I'm confused! | 五種情況 |
| Edge | 1 2 3<br>3 1 2 | A equals B | A equals B | 順序不同的相同集合 |

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
| UVa 496 / Simply Subsets | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
