bool matchFirst(char* s, char* p) {
	if (*p == *s || (*p == '.' && *s!='\0'))
		return true;
	return false;
}

bool isMatch(char* s, char* p) {
	if (*s == '\0' && *p == '\0')
		return true;
	if (*(p + 1) != '*') {
		if (!matchFirst(s, p))
			return false;
		return isMatch(s + 1, p + 1);
	}
	else {
		if (isMatch(s, p + 2))
			return true;
		while (matchFirst(s, p)) {
			if (isMatch(++s, p + 2))
				return true;
		}
		return false;
	}

}

int main()
{
	printf("%d\n",isMatch("aab", "c*a*b*"));
	printf("%d\n", isMatch("aa", ".*"));
	printf("%d\n", isMatch("aa", ".c*c"));
	printf("%d\n", isMatch("ab", ".*"));
	printf("%d\n", isMatch("aaaaa", "a*aaa*"));
	printf("%d\n", isMatch("aabbcc", "a*b*cc"));
	printf("%d\n", isMatch("", ""));
	getchar();
	return 0;
}

