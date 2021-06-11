#每次出差分包，需要修改一下这个新版本号
#cd android
NewVersionDir="20210611"
NewVersion=${NewVersionDir:2}
NewDiffVersion=${NewVersionDir}
SaveFilesDir=../../../software_version/ibotn_base/$NewVersionDir/

if [[ ! -d $SaveFilesDir ]]; then
	echo "SaveFilesDir: $SaveFilesDir"
	mkdir -p $SaveFilesDir
fi

#每次出差分包，要确认旧版本号有没有遗漏掉，如果有遗漏，需要添加到列表中 (171103 171125 没有在ota服务器列表)
OldVersionList=(20191111 20191122 20191204 20200111 20201028 20201203)
for k in ${OldVersionList[@]}
do
	oldTargetVersion=${k:2}
	OldDiffVersion=${k}
	OldVersionName=../../../software_version/ibotn_bak/bubble_gum-target_files-$oldTargetVersion.zip
	NewVersionName=../../../software_version/ibotn_bak/bubble_gum-target_files-$NewVersion.zip
	DiffVersionName=../../../software_version/ibotn_bak/diff${OldDiffVersion}_${NewDiffVersion}.zip
	echo "OldVersionName: $OldVersionName"
	echo "NewVersionName: $NewVersionName"
	echo "DiffVersionName: $DiffVersionName"
	./build/tools/releasetools/ota_from_target_files -i $OldVersionName $NewVersionName $DiffVersionName
	#cp $DiffVersionName $SaveFilesDir
done
