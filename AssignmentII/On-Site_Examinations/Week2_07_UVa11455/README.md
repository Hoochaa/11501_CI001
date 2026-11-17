# Code Review Report: UVa 11455 - Behold my quadrangle

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11455
- **Problem Title:** Behold my quadrangle
- **Problem Link:** https://onlinejudge.org/external/114/11455.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-09-15）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/s1151536-UVa11455.cpp](./src/s1151536-UVa11455.cpp)
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
		int a=0, b=0, c=0, d=0;
		cin >> a >> b >> c >> d;
		int m=0;
		if(a>m){m=a;}
		if(b>m){m=b;}
		if(c>m){m=c;}
		if(d>m){m=d;}
		if (a+b+c+d < m*2){
			cout << "banana" << endl;
		}else if (a==b && b==c && c==d){
			cout << "square" << endl;
		}else if((a==b && c==d)or(a==c && b==d)){
			cout << "rectangle" << endl;
		}else{
			cout << "quadrangle" << endl;
		}
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 首次提交即 AC：先找最長邊判斷能否成形，再判斷正方形、長方形。
- ⚠️ AI 額外檢查（本 OJ 測資沒測到）：
   1. 長方形只檢查了 `(a==b && c==d)` 與 `(a==c && b==d)`，漏了 `(a==d && b==c)`，輸入 `1 2 2 1` 會被判成 quadrangle。
   2. 用 `<` 判斷 banana，當最長邊剛好等於其他三邊和（退化成一條線）時會判成 quadrangle；建議用 `<=`。
- 更穩的寫法：四個數 `sort` 後再判斷。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 4<br>10 8 7 6<br>9 1 9 1<br>29 29 29 29<br>5 12 30 7 | quadrangle<br>rectangle<br>square<br>banana | quadrangle<br>rectangle<br>square<br>banana | 題目範例 |
| Edge | 1<br>1 2 2 1 | rectangle | quadrangle | 對邊以 a==d、b==c 排列 |
| Boundary | 1<br>1 1 1 3 | banana | quadrangle | 最長邊 = 其他三邊和（退化） |

⚠️ 有 2 筆測試的實際結果與預期不符，詳見第 5 節診斷。

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
| UVa 11455 / Behold my quadrangle | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
