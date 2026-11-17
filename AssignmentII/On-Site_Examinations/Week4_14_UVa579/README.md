# Code Review Report: UVa 579 - Clock Hands

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 579
- **Problem Title:** Clock Hands
- **Problem Link:** https://onlinejudge.org/external/5/579.pdf
- **Language / Version:** C++
- **Submission Result:** Accepted（共提交 1 次，2026-09-29）
- **Source Code (Initial/Fail):** 無（首次提交即為最終版本）
- **Source Code (Final/Accepted):** [src/s1151536-UVa579.cpp](./src/s1151536-UVa579.cpp)
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
	string t="";
	while(getline(cin, t)){
		if(t=="0:00"){
			break;
		}
		int a, b, c, d;
		if(t.size()==5){
			a=int(t[0]); b=int(t[1]); c=int(t[3]); d=int(t[4]);	
		}else{
			a=48; b=int(t[0]); c=int(t[2]); d=int(t[3]);
		}
		a-=48; b-=48; c-=48; d-=48;
		int h=a*10+b, m=c*10+d;
		float h_ang=h*30+m*0.5;
		float m_ang=m*6;
		float ang1=max(h_ang, m_ang);
		float ang2=min(h_ang, m_ang);
		float ans = min(ang1-ang2, 360-ang1+ang2);
		cout << fixed << setprecision(3) << ans << endl;
	}
	return 0;
}
```

**Why it works（AI 診斷，請讀懂後改寫成自己的話）:**

- 時針角度 = h×30 + m×0.5，分針角度 = m×6，取差值與 360 減差值的較小者，輸出 3 位小數。首次提交即 AC。
- AI 建議：時間字串可用 `scanf("%d:%d", &h, &m)` 直接解析，不需判斷長度與手動減 48；`float` 改用 `double` 精度較安全。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 12:00<br>9:00<br>8:10<br>0:00 | 0.000<br>90.000<br>175.000 | 0.000<br>90.000<br>175.000 | 題目範例 |
| Edge | 12:59<br>0:00 | 35.500 | 35.500 | 12 點附近 |
| Boundary | 6:00<br>0:00 | 180.000 | 180.000 | 最大夾角 |

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
| UVa 579 / Clock Hands | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
