# 알고리즘 학습

알고리즘을 배우고 적용하면서 익숙해지는 것을 목표

* 참고한 사이트

  *[백준](https://www.acmicpc.net/)
  
  *[코드업](https://codeup.kr/)
  
  *[메일코딩](https://mailprogramming.com/)
  
  *[프로그래머스](https://programmers.co.kr/)
  
  *[안경잡이개발자](https://blog.naver.com/ndb796/)
  
  *[라이](https://blog.naver.com/kks227/)
  
  *[박트리](https://baactree.tistory.com/)
  
  *[개발자지망생](https://blockdmask.tistory.com/)
  
  
  
# String
## string::find 와 string::npos
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
<pre>
  
  
