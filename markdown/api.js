
    // 编辑器对象
    var testEditor;
    //函数入口
    $(function () {


        //编辑器初始化 	
        testEditor = editormd("test-editormd", {
            width: "100%",
            height: 768,
            previewTheme: (localStorage.previewTheme) ? localStorage.previewTheme : "monokai",
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

    function  setEditorTheme(theme){
        testEditor.setEditorTheme(theme);
    }
    function setPreviewTheme(theme){
        testEditor.setPreviewTheme(theme);
    }

function getTags() {
   return testEditor.getPreviewedHTML();
}

    //打开实时预览
    function openLiveWatch() {
        testEditor.watch();
    }
    function closeLiveWatch() {
        testEditor.unwatch();
    }

    //只显示预览
    function openPreview() {
        testEditor.previewing();
        $("#test-editormd > a").hide();
    }
    function closePreview() {
        testEditor.previewed();
    }

    function getMarkdown() {
         return testEditor.getValue();
     }

     function setMarkdown(mdText){
         testEditor.setMarkdown(mdText);
     }
