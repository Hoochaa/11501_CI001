# Code Review Report: UVa 11388 - GCD LCM

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11388
- **Problem Title:** GCD LCM
- **Problem Link:** https://onlinejudge.org/external/113/11388.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 5 次，2026-10-06）
- **Source Code (Initial/Fail):** [src/s1151536-UVa11388_fail.cpp](./src/s1151536-UVa11388_fail.cpp)（Runtime Error）
- **Source Code (Final/Accepted):** [src/s1151536-UVa11388.cpp](./src/s1151536-UVa11388.cpp)
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
	while(n--){
		long long G=0, L=0;
		cin >> G >> L;
		vector<long long> vec;
		for (int i=G; i*G<=L; i++){
			vec.push_back(i*G);
		}
		if(vec.size()<2){
			cout << -1 << endl;
		}
		cout << vec[0] << " " << vec[-1] << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- `vec[-1]`：C++ 不支援 Python 的負索引，存取到陣列外導致 Runtime Error。
- `vec.size()<2` 時輸出 -1 後沒有 `continue`，仍會執行下一行而越界。
- `for (int i=G; i*G<=L; ...)` 從 G 開始乘，起點也不對；且列舉方式在 L 很大時會 TLE（第 3 次提交即為 TLE）。

### Correct Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	while(n--){
		long long G=0, L=0;
		cin >> G >> L;
		if(L%G != 0){
			cout << -1 << endl;
			continue;
		}
		cout << G << " " << L << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 觀察到數學性質：若 L 是 G 的倍數，最小的 a 就是 G、對應 b = L；否則無解。
- 因此直接判斷 `L % G`，O(1) 完成。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 2<br>1 2<br>3 4 | 1 2<br>-1 | 1 2<br>-1 | 題目範例 |
| Edge | 1<br>5 5 | 5 5 | 5 5 | G = L |
| Boundary | 1<br>1 2147483647 | 1 2147483647 | 1 2147483647 | L 很大 |

所有測試皆通過。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 暴力列舉倍數 | 數學性質 O(1) |
| Edge Cases | 無解時未 continue | 先判斷再輸出 |
| Output Handling | 同 | 同 |
| Complexity | O(L/G) | O(1) |
| Code Quality | 負索引 vec[-1] | 無 |

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
| UVa 11388 / GCD LCM | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
