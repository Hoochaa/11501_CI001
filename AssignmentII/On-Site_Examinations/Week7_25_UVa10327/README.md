# Code Review Report: UVa 10327 - Flip Sort

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10327
- **Problem Title:** Flip Sort
- **Problem Link:** https://onlinejudge.org/external/103/10327.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 2 次，2026-10-20）
- **Source Code (Initial/Fail):** [src/UVa10327_fail.cpp](./src/UVa10327_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa10327_latest.cpp](./src/UVa10327_latest.cpp)（最新一次提交，尚未 AC）
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
	int n=0, buf=0;
	vector<int> vec;
	while(cin >> n){
		vec.assign(n, 0);
		for (int i=0; i<n; i++){
			cin >> buf;
			vec[i] = buf;
		}
		int ans=0;
		for (int j=0; j<n-1; j++){
			for (int k=j+1; k<n; k++){
				if(vec[j] > vec[k]){
					ans++;
					swap(vec[j], vec[k]);
				}
			}
		}
		cout << "Minimum exchange operations : " << ans << endl;
	}

	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 第一版用與 UVa 299 相同的「交換排序」計數。AI 窮舉驗證：數字**有重複**時，這個次數不等於相鄰交換次數。例如 `2 2 1 1 3` 正確答案是 4，程式輸出 2。
- 第二版（最新）改成反轉區間的方式，與題目「只能交換相鄰兩數」的定義不符，`4 3 2 1` 輸出 1（正確為 6），比第一版更偏離。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int n=0, buf=0;
vector<int> vec;
int main(){
	
	while(cin >> n){
		if(n==0){
			cout << "Minimum exchange operations : 0" << endl;
			continue;
		}
		vec.assign(n, 0);
		for (int i=0; i<n; i++){
			cin >> buf;
			vec[i] = buf;
		}
		int ans=0;
		for (int i=0; i<n; i++){
			if(vec[i] > vec[n-1]){
				for (int j=i; j<(n-i)/2+i; j++){
					swap(vec[j], vec[n-1-j]);
				}
				ans += 1;
			}
		}
		cout << "Minimum exchange operations : " << ans << endl;
	}

	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
- 答案就是逆序數對的個數：計算有多少 (i, j) 滿足 i < j 且 a[i] > a[j]（注意是嚴格大於，相等不算）。N ≤ 1000，雙層迴圈 O(N²) 足夠；或用真正的相鄰交換 bubble sort 計數。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal (fail code) | 3<br>1 2 3<br>3<br>2 3 1 | Minimum exchange operations : 0<br>Minimum exchange operations : 2 | （與預期相同） | 題目範例 |
| Edge (fail code) | 5<br>2 2 1 1 3 | Minimum exchange operations : 4 | Minimum exchange operations : 2 | 有重複數字 |
| Edge | 4<br>4 3 2 1 | Minimum exchange operations : 6 | Minimum exchange operations : 1 | 完全反序（最新版本） |

⚠️ 有 2 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | 交換排序計數 | 反轉區間（更偏離） |
| Edge Cases | 重複數字錯 | 也錯 |
| Output Handling | 同 | 同 |
| Complexity | O(N²) | O(N²) |
| Code Quality | — | 全域變數 |

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
| UVa 10327 / Flip Sort | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
