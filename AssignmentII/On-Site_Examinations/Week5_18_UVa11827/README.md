# Code Review Report: UVa 11827 - Maximum GCD

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11827
- **Problem Title:** Maximum GCD
- **Problem Link:** https://onlinejudge.org/external/118/11827.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 1 次，2026-10-06）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/UVa11827_latest.cpp](./src/UVa11827_latest.cpp)（最新一次提交，尚未 AC）
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

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	while(n--){
		long long G=0, L=0;
		cin >> G >> L;
		vector<int> G_vec;
		vector<int> res;
		for (int i=1; i*G<=L; i++){
			G_vec.push_back(i*G);
		}
		for (int i=0; i<G_vec.size(); i++){
			if(L%G_vec[i]==0){
				res.push_back(G_vec[i]);
			}
		}
		sort(res.begin(), res.end());
		if(res.size()<2){
			cout << -1 << endl;
			continue;
		}
		cout << res[0] << " " << res[1] << endl;
		
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 唯一一次提交的程式碼是 **UVa 11388（GCD LCM）** 的解法，交錯題目了（讀入 G、L 兩個數）。
- 修正方向（AI 建議，請自行實作後重新提交）：
   1. 每組資料是一整行、個數不固定的整數：先 `cin >> n; cin.ignore();`，再用 `getline` + `stringstream` 讀出整行的所有數字。
   2. 對所有兩兩配對計算 `__gcd`，取最大值。數字最多 100 個，O(M²) 足夠。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 3<br>10 20 30 40<br>7 5 12<br>125 15 25 | 20<br>1<br>25 | 10 20<br>-1<br>-1 | 題目範例（每行數字個數不同） |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

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
| UVa 11827 / Maximum GCD | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
