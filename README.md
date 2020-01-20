# 알고리즘 정복하기

* 좋은 개발자가 되기 위해 하루동안 학습한 알고리즘 내용이나 경험들을 기록을 통해 남긴다.
* 다양한 알고리즘을 통해서 탄탄한 기본기를 갖추는 것이 목표이다.
* 여기서의 내용은 알고리즘이여도 되고, 알고리즘을 풀 때 사용한 함수나 문법의 경험, 자료구조도 작성한다.
* 지금은 못하더라도 조급해지지 않고 꾸준히 열심히 하자!

[namjunemy]님의 Github를 보고 나 역시 조금씩이나마 기록을 남기고자 시작했다.
[namjunemy]: https://github.com/namjunemy/TIL

# 다짐
* 중요한 것은 모르는 부분을 찾고자 할 때, 추가적인 검색의 비용이 들지 않도록 자세히 기록한다.
* 참고한 자료는 꼭 출처를 남기자.
* 어려워도 포기하지 말고 해보자.

# Algorithm
# C
# C++
## 1. String
### 1.1. string::find 와 string::npos
`string::find` 찾는 문자열의 첫 번째 인덱스를 반환하는 함수 <br>
`string::npos` 찾는 문자열이 없는 경우에는 `string::npos`를 반환한다. <br>

<pre>
<code>
string str = "Hello World";
if(str.find("World") != string::npos)
{
  cout << "찾는 문자열이 있습니다. 해당 문자열의 시작 인덱스 번호는 << str.find("World") << "입니다. << endl;
}
else
{
  cout << "찾는 문자열이 없습니다." << endl;
}
</code>
</pre>


  
  
