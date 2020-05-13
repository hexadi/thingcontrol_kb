function FilterCode(str) {
	if (/^\(char \*\)"(.*)"$/.test(str)) {
		var text = /^\(char \*\)"(.*)"$/.exec(str)[1];
		return '"' + encodeURI(text) + '"';
	}
	
	return str;
}

Blockly.JavaScript['thingcontrol_set_access_token'] = function(block) {
	var value_token = block.getFieldValue('token') || '""';
	var code = '#EXTINC#include <thingcontrol.h>#END' 
	code += 'ThingControl().setAccessToken("' + value_token + '");\n'
	return code;
};

Blockly.JavaScript['thingcontrol_send'] = function(block) {
    var value_key = Blockly.JavaScript.valueToCode(block, 'key', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	var value_message = Blockly.JavaScript.valueToCode(block, 'message', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	// TODO: Assemble JavaScript into code variable.
    var code = '';
    code += 'ThingControl().setKey(' + FilterCode(value_key) + '); ';
	code += 'ThingControl().setMessage(' + FilterCode(value_message) + '); ';
	code += 'ThingControl().sendM();\n';
	return code;
};

Blockly.JavaScript['thingcontrol_receive_attr'] = function(block) {
	var statements_handler = Blockly.JavaScript.statementToCode(block, 'handler');
	var value_temt = block.getFieldValue('temt');
	// TODO: Assemble JavaScript into code variable.
    var code = '';
    code += 'if (ThingControl().checkAttr("' + value_temt + '")) { \n';
	code += statements_handler;
	code += ' }\n';
	return code;
};

Blockly.JavaScript['thingcontrol_attr_value'] = function(block) {
	var code = 'ThingControl().AttrValue()';
  return [code, Blockly.JavaScript.ORDER_ATOMIC];
};

/*Blockly.JavaScript['thingcontrol_gtest'] = function(block) {
	var code = 'ThingControl().gTest();\n';
	return code;
};*/