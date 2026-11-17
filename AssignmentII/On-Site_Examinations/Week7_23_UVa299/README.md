# Code Review Report: UVa 299 - Train Swapping

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 299
- **Problem Title:** Train Swapping
- **Problem Link:** https://onlinejudge.org/external/2/299.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-10-20）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/UVa299_ac.cpp](./src/UVa299_ac.cpp)
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
	int n=0;
	cin >> n;
	for (int i=0; i<n; i++){
		int num=0;
		vector<int> vec;
		cin >> num;
		for (int j=0; j<num; j++){
			int buf=0;
			cin >> buf;
			vec.push_back(buf);
		}
		int ans=0;
		for (int j=0; j<num-1; j++){
			for (int k=j+1; k<num; k++){
				if(vec[j] > vec[k]){
					ans++;
					swap(vec[j], vec[k]);
				}
			}
		}
		cout << "Optimal train swapping takes " <<  ans  << " swaps." << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 計算交換次數。首次提交即 AC。
- AI 檢查：你用的是「交換排序」（第 j 個與後面所有較小者交換），不是相鄰交換的 bubble sort。AI 以窮舉驗證：**當所有數字都不相同時**，這個次數剛好等於逆序數對，所以本題正確（車廂編號不重複）。但有重複數字時就不相等——這正是 UVa 10327 WA 的原因（見 Week7_25）。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 3<br>3<br>1 3 2<br>4<br>4 3 2 1<br>2<br>2 1 | Optimal train swapping takes 1 swaps.<br>Optimal train swapping takes 6 swaps.<br>Optimal train swapping takes 1 swaps. | （與預期相同） | 題目範例 |
| Edge | 1<br>0 | Optimal train swapping takes 0 swaps. | Optimal train swapping takes 0 swaps. | L = 0 |

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
| UVa 299 / Train Swapping | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
