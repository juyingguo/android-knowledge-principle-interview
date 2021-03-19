// <script language="JavaScript">
			function alertTip(){
				alert("hello1");
			}
		// </script>
		
String.prototype.compare = function(str) {
	//不区分大小写
	if(this.toLowerCase() == str.toLowerCase()) {
		return true;
	} else {
		return false;
	}
}