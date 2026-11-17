# Code Review Report: UVa 10931 - Parity

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10931
- **Problem Title:** Parity
- **Problem Link:** https://onlinejudge.org/external/109/10931.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-10-13）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/s1151536-UVa10931.cpp](./src/s1151536-UVa10931.cpp)
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
	long long n=0;
	while(cin >> n && n!=0){
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		long long p=log(n)/log(2);
		int c=0;
		cout << "The parity of ";
		while(p>=0){
			long long num = pow(2, p);
			if(n/num==1)c++;
			cout << (n/num);
			n = n%num;
			p--;
		}
		cout << " is " << c << " (mod 2)." << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 轉二進位並計算 1 的個數。首次提交即 AC。
- ⚠️ AI 額外檢查：與 UVa 11185 一樣使用 `log(n)/log(2)` 與 `pow`。實測 1~65535 都正確（2 的次方在浮點中可精確表示），但同樣的寫法在 11185（三進位）就出錯了。建議統一改用 `n % 2`、`n /= 2` 的整數寫法。
- `while(cin >> n && n!=0)` 之後的 `if(n==0)` 永遠不會成立，可刪除。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 1<br>2<br>10<br>21<br>0 | The parity of 1 is 1 (mod 2).<br>The parity of 10 is 1 (mod 2).<br>The parity of 1010 is 2 (mod 2).<br>The parity of 10101 is 3 (mod 2). | （與預期相同） | 題目範例 |
| Boundary | 2147483647<br>0 | The parity of 1111111111111111111111111111111 is 31 (mod 2). | （與預期相同） | 2^31 − 1 |
| Edge | 536870912<br>0 | The parity of 1 followed by 29 zeros is 1 (mod 2). | （與預期相同） | 2 的次方 |

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
| UVa 10931 / Parity | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
