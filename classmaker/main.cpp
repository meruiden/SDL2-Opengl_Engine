
#include <iostream>
#include <fstream>
#include <string>
#include <locale>


int main () {
	std::ofstream myfile;

	std::string classname;
	std::cout << "Enter the classname" << std::endl;
	std::cin >> classname;
	std::locale loc;



	std::string fixedClassname;

	std::toupper(fixedClassname[1],loc);
	for (std::string::size_type i = 0; i < classname.length(); ++i){
		if(i == 0){
			fixedClassname += std::toupper(classname[i],loc);
		}else{
			fixedClassname += std::tolower(classname[i],loc);
		}
	}
	std::string lowercaseclass;
	for (std::string::size_type i = 0; i < classname.length(); ++i){
		lowercaseclass += std::tolower(classname[i],loc);
	}
	std::string cppContent;
	cppContent += "#include \"" ;
	cppContent += lowercaseclass;
	cppContent += ".h\" \n \n";
	cppContent += fixedClassname;
	cppContent += "::";
	cppContent += fixedClassname;
	cppContent += "(){\n \n}";

	cppContent += "\n \n";
	cppContent += fixedClassname + "::" + "~" + fixedClassname + "(){\n\n}";

	myfile.open (lowercaseclass + "." + "cpp");
	myfile << cppContent;
	myfile.close();


	std::string hContent;
	hContent += "#ifndef ";
	std::string uppercaseclass;
	for (std::string::size_type i = 0; i < classname.length(); ++i){
		uppercaseclass += std::toupper(classname[i],loc);
	}
	hContent += uppercaseclass + "_H\n";
	hContent += "#define " + uppercaseclass + "_H\n\n";
	hContent += "class " + fixedClassname + "\n{\n";
	hContent += "public:\n\nprivate:\n\n};\n\n#endif";

	myfile.open (lowercaseclass + "." + "h");
	myfile << hContent;
	myfile.close();




	return 0;
}