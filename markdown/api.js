
    // 编辑器对象
    var testEditor;
    //函数入口
    $(function () {


        //编辑器初始化 	
        testEditor = editormd("test-editormd", {
            width: "100%",
            height: 768,
            previewTheme: (localStorage.previewTheme) ? localStorage.previewTheme : "default",
            editorTheme: (localStorage.editorTheme) ? localStorage.editorTheme : "default",
            path: 'lib/',
            sequenceDiagram : true,  //支持时序图
            tocContainer : "#toc"
        });

       //隐藏工具栏
        try {
            testEditor.hideToolbar();
        }
        catch(err) {}

        try{
            testEditor.fullscreen();
        }catch (err){}

    });

    function getEditorThemes() {
        return editormd.editorThemes;
    }

    function getPreviewThemes() {
        return editormd.previewThemes;
    }





