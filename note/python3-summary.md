# Python3

## 자료형

- 구성 요소
    - Number

        ```python
        # 1. integer (10진 정수)
        a = 123

        # 2. float (실수)
        a = 1.2
        a = 4.24e-10 # (= 4.24 * 10^-10)

        # 3. octal (8진수)
        a = 0o123
        a = 0O321

        # 4. hexadecimal (16진수)
        a = 0x8ff
        a = 0xABC

        # 연산자
        # 1. 사칙연산 (+, -, *, /)
        # 2. 제곱 (**) -> print(2**3)
        # 3. 나머지 (%)
        # 4. 몫 (//)
        ```

    - String

        ```python
        # 1. String 생성
        ## ', "을 포함하여 출력 (: escape code)
        s = '"Chef\'s recommendation" is...' # "Chef's recommendation" is...
        ## 개행 포함하여 출력
        s = '''
        Life is too short
        You need python
        '''

        # 2. String 연산
        print("py" + "thon") # '+' -> python
        print("py" * 2) # '*' -> pypy

        # 3. String length
        print(len("python") # -> 6

        # 4. String indexing and slicing
        s = "Life is too short, You need Python"
        print(s[0]) # -> L
        print(s[-1]) # -> n
        print(s[:4]) # -> Life ## 0이상 4미만!

        # 5. String formatting
        print("I ate %d apples." % 3) # -> I ate 3 apples.
        print("%s apples, %d%% grapes" % (2.5, 50)) # -> 2.5 apples, 50% grapes

        print("{0} apples, {1}% grapes".format(2.5, 50)) # -> 2.5 apples, 50% grapes
        print("{apple} apples, {grape}% grapes".format(apple=2.5, grape=50)) # -> 2.5 apples, 50% grapes

        print("{0:>10}".format("hi")) # -> '        hi' (10칸안에서 오른쪽 정렬)

        name = '홍길동'
        age = 30
        print(f'나의 이름은 {name}입니다. 나이는 {age}입니다.')

        # 6. String 관련 함수들
        ## count
        print("python".count('p')) # -> 1
        ## find
        print("python".find('p')) # -> 0
        print("python".find('k')) # -> -1
        ## join
        print(",".join("abcd")) # -> a,b,c,d
        ## upper and lower
        print("hi".upper()) # -> HI
        print("HI".lower()) # -> hi
        ## 공백 지우기 (lstrip, rstrip, strip)
        print(" hi ".lstrip()) # -> 'hi '
        print(" hi ".rstrip()) # -> ' hi'
        print(" hi ".strip()) # -> 'hi'

        ## replace
        print("Life is good".replace("Life", "Money")) # -> Money is good

        ## split
        print("Life is good".split()) # -> ['Life', 'is', 'good']
        print("a:b:c:d".split(':')) # -> ['a', 'b', 'c', 'd']
        ```

        - 주의
            - String의 요솟값 바꿀 수 없다 (String은 immutable한 자료형이기 때문)
                - 따라서 slicing으로 새로운 String 만들어 재할당

                    ```python
                    a = "Pithon"
                    a = a[:1] + 'y' + a[2:]
                    print(a)
                    ```

    - list

        ```python
        # 1. list 사용법
        odd = [1, 3, 5, 'seven', 'nine', [11, 13, 15]] # 어떤 자료형도 OK
        a = []
        a = list()

        # 2. 삼중 리스트에서 인덱싱하기
        a = [1, 2, ['a', 'b', ['Life', 'is']]]
        print(a[2][2][0]) # 'Life'

        # 3. slicing
        a = [1, 2, 3, 4, 5]
        b = a[:2] # 0, 1번 -> [1, 2]
        b = a[2:] # 2, 3, 4번 -> [3, 4, 5]

        # 4. list 연산
        ## '+'
        a = [1, 2, 3]
        b = [4, 5, 6]
        print(a + b) # [1, 2, 3, 4, 5, 6] ## 문자열에서 합치는 것과 같음
        ## '*'
        print(a * 2) # [1, 2, 3, 1, 2, 3] ## 반복 효과

        # 5. 길이 구하기
        print(len(a)) # 3

        # 6. 값 수정
        a = [1, 2, 3]
        a[2] = 4
        print(a) # [1, 2, 4]

        # 7. 요소 삭제
        a = [1 ,2, 3, 4, 5]
        del a[:2]
        print(a) # [3, 4, 5]

        # 8. 요소 추가
        a.append(6)
        print(a) # [3, 4, 5, 6]

        # 7. 정렬 obj.sort()
        a = ['a', 'c', 'b']
        a.sort() # ['a', 'b', 'c']
        a.reverse() # ['c', 'b', 'a']

        # 8. 위치 반환 obj.index()
        a.index('b') # 1

        # 9. 요소 삽입 obj.insert(a, b)
        a = [1, 2, 3]
        a.insert(0, 1) # [1, 1, 2, 3]

        # 10. 요소 제거 obj.remove(x)
        ## 가장 첫번째로 나오는 x 삭제 (* 전체 삭제 아님)
        a.remove(1) # [1, 2, 3]

        # 11. pop()
        ## pop(): 리스트의 맨 마지막 요소 반환하고 삭제
        a = [1, 2, 3]
        a.pop() # 3 -> [1, 2]

        ## pop(x): 리스트의 x번째 요소를 반환하고 삭제
        a.pop(1) # 1 -> [1]

        # 12. count(x)
        a = [1, 2, 3, 1]
        a.count(1) # 2

        # 13. list extend
        a = [1, 2, 3]
        a.extend([4, 5]
        print(a) # [1, 2, 3, 4, 5]
        ## a.extend([4, 5])는 a += [4, 5]와 동일하다
        ```

    - tuple

        ```python
        # 1. tuple 사용법
        ## tuple은 값 변경 불가! (<-> 리스트)
        t = ()
        t = (1, ) # 요소 1개일 때 ',' 붙여야 함
        t = 1, 2, 3 # 괄호 생략 가능
        t = ('a', 'b', ('ab', 'cd'))

        # 2. tuple 요솟값 삭제, 삭제 불가!
        t = (1, 2, 'a', 'b')
        del t[0], t[0] = 'c' ### 불가!

        # 3. tuple 인덱싱
        t1 = (1, 2, 'a', 'b')
        t2 = (3, 4)
        ## slicing
        t1[1:] # (2, 'a', 'b')
        ## '+'
        print(t1 + t2) # (1, 2, 'a', 'b', 3, 4)
        ## '*'
        print(t2 * 2) # (3, 4, 3, 4)

        # 4. tuple 길이 구하기
        print(len(t2)) # 2
        ```

    - dictionary

        ```python
        # 1. dictionary 사용법
        dic = {'name': 'hong', 'id': 20161160}
        dic = {'subject': [1, 2, 3]}

        # 2. 쌍 추가, 삭제
        ## 추가
        a = {1: 'a'}
        a[2] = 'b'
        print(a) # {1: 'a', 2:'b'}
        ## 삭제
        del a[1]
        print(a) # {2:'b'}

        # 3. key사용해서 value얻기
        ## 대괄호 안에 넣기
        grade = {'pey': 10, 'julliet': 99}
        print(grade['pey']) # 10
        ### 존재하지 않는 key로 값 가져오려는 경우: 오류 발생!

        ## get() 함수
        print(grade.get('pey')) # 10
        ### 존재 하지 않는 key로 값 가져오려는 경우: None 반환된다!
        ### get(x, default)
        print(grade.get('jay', 'not_exist') # 존재하지 않은 key인 경우 디폴트 값 반환

        # 4. keys(): key 리스트 만들기
        a = {'name': 'pey', 'phone': '0119993323', 'birth': '1118'}
        a.keys() # dict_keys(['name', 'phone', 'birth'])
        list(a.keys()) # ['name', 'phone', 'birth']

        # 5. values(): value 리스트 만들기
        a.values() # dict_values(['pey', '0119993323', '1118'])
        list(a.values()) # ['pey', '0119993323', '1118']

        # 6. items(): key, value 쌍 얻기
        a.items() # dict_items([('name', 'pey'), ('phone', '0119993323'), ('birth', '1118')])

        # 7. clear(): key, value 쌍 모두 지우기
        a.clear()
        print(a) # {}

        # 8. in: 해당 key가 딕셔너리 안에 있는지 조사
        a = {'name':'pey', 'phone':'0119993323', 'birth': '1118'}
        print('name' in a) # True
        print('email' in a) # False
        ```

    - set

        ```python
        # 1. set 사용법
        ## set은 중복 허용X, unordered
        s = set([1, 2, 3]) # {1, 2, 3}
        s = set("Hello") # {'e', 'H', 'l', 'o'}

        ### 중복을 허용하지 않는 set의 특징 -> 자료형의 중복을 제거하기 위한 필터역할로 사용
        li = list(s) # [1, 2, 3]
        tu = tuple(s) # (1, 2, 3)

        # 2. 교집합, 합집합, 차집합
        s1 = set([1, 2, 3, 4, 5, 6])
        s2 = set([4, 5, 6, 7, 8, 9])

        ## 교집합 &, intersection()
        s1 & s2 # {4, 5, 6}
        s1.intersection(s2) # {4, 5, 6}

        ## 합집합 |, union()
        s1 | s2 # {1, 2, 3, 4, 5, 6, 7, 8, 9}
        s1.union(s2) # {1, 2, 3, 4, 5, 6, 7, 8, 9}

        ## 차집합 -, difference()
        s1 - s2 # {1, 2, 3}
        s2 - s1 # {8, 9, 7}
        s1.difference(s2) # {1, 2, 3}
        s2.difference(s1) # {8, 9, 7}

        # 3. 값 추가, 제거
        ## add(): 값 한개 추가
        s1 = set([1, 2, 3])
        s1.add(4)
        print(s1) # {1, 2, 3, 4}

        ## update(): 값 여러개 추가
        s1 = set([1, 2, 3])
        s1.update([4, 5, 6])
        print(s1) # {1, 2, 3, 4, 5, 6}

        ## remove(): 특정 값 제거
        s1 = set([1, 2, 3])
        s1.remove(2)
        print(s1) # {1, 3}
        ```

    - bool

        ```python
        # 1. bool 사용법
        b1 = True
        b2 = False

        a = [1, 2, 3, 4]
        while a:
        	print(a.pop()) # 4\n3\n2\n1\n

        # 2. bool 연산
        bool('python') #True
        bool('') #False
        ```

        - 자료형의 참과 거짓
            - string, list, tuple, dictionary 등의 값이 비어있으면 False

            [자료형의 참과 거짓](https://www.notion.so/4bafb3cc02da47b3b672fb26f8f83c89)

    - 변수
        - 변수는 어떻게 만들까?
            - 대입연산자 '=' (assignment) 사용
        - 파이썬의 변수란?
            - 객체를 가리키는 것
        - 변수의 메모리 주소 확인 방법?

            ```python
            a = [1, 2, 3]
            print(id(a)) # 4303029896 주소값 출력
            ```

        - 리스트 복사?
            - b = a는 동일한 객체를 가리킨다

                ```python
                a = [1, 2, 3]
                b = a
                ## 복사 시 동일한 객체 가리킴

                if id(a) = id(b): print("same!") # same!
                if a is b: print("same!") # same!
                ```

            - 그렇다면 값만 복사하고 다른 객체로 복사하는 방법?
                1. [:] 사용

                    ```python
                    a = [1, 2, 3]
                    b = a[:]
                    ```

                2. copy 모듈 사용 ([:]과 동일)

                    ```python
                    from copy import copy
                    b = copy(a)
                    ```

        - 변수 만드는 여러가지 방법

            ```python
            # 1. use tuple
            a, b = ('python', 'life')
            (a, b) = 'python', 'life'

            # 2. use list
            [a, b] = ['python', 'life']

            # 3. 여러 개의 변수에 같은 값 대입
            a = b = 'python'

            # swap 효과
            a = 3
            b = 5
            a, b = b, a
            ```

## 기본 문법

- 구성 요소
    - 제어문
        - if

            ```python
            # 1. if문 구조
            money = 2000
            if money >= 3000:
            	print("taxi")
            elif money >= 1000:
            	print("bus")
            else:
            	print("walk")

            # 2. 조건 판단 연산자
            ## and, or, not
            money = 2000
            card = True
            if money >= 3000 or card:
            	print("taxi")

            # 3. x in s, x not in s
            ## list, tuple, string에 적용 가능
            print(1 in [1, 2, 3]) # in list
            print('j' not in ('a', 'b', 'c')) # not in tuple
            print('p' in 'python') # in string
            ```

        - while

            ```python
            # 1. while문 구조
            n = 10
            while n > 0:
            	print(n % 2)
            	n = n // 2
            ```

        - for

            ```python
            # 1. for문 구조
            numbers = ['one', 'two', 'three']
            for num in numbers:
            	print(num)

            a = [(1, 2), (3, 4), (5, 6)]
            for (first, second) in a:
            	print(first + second)

            # 2. range()
            for i in range(2, 10): # 범위: i>=2 && i<10
            	for j in range(1, 10):
            		print(i*j, end=' ') # end=' ': 같은 줄에서 띄어쓰기만 하기
            	print('')

            # 3. list comprehension
            a = [num for num in range(1, 11)] # [1, 2, ... , 10]
            result = [num for num in a if num % 2 == 0] # 짝수만 리스트에 담김
            result = [num for num in range(1, 11) if num % 2 == 0] # 결과 동일

            gugudan = [i*j for i in range(2, 10) for j in range(1, 10]
            ```