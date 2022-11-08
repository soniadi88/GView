def GetCharType(ch):
	if ch in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_":
		return "Word"
	if ch in "0123456789":
		return "Number"
	if (ch==' ') or (ch=='\t'):
		return "Space"
	if (ch=='\n') or (ch=='\r'):
		return "NewLine"
	if ch=='#':
		return "Comment"
	if ch=='.':
		return "Directive"
	if ch in "!%+-=^&|*:?~\/><.":
		return "Operator"
	if ch == '{':
		return "BlockOpen"
	if ch == '}':
		return "BlockClose"
	if ch == '[':
		return "MemAddrOpen"
	if ch == ']':
		return "MemAddrClose"
	if ch == '(':
		return "ExpressionOpen"
	if ch == ')':
		return "ExpressionClose"
	if ch==',':
		return "Comma"
	if ch==';':
		return "Semicolumn"
	if (ch=='\"') or (ch=='\''):
		return "String"
	return "Invalid"

s = "uint8 Cpp_Groups_IDs[] = {"
for i in range(0,128):
	s += GetCharType(chr(i))+","
s = s[:-1]+"};"
print(s)                                                                     
