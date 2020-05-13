Blockly.Blocks['thingcontrol_set_access_token'] = {
	init: function() {
		this.appendDummyInput()
        .appendField(Blockly.Msg.THINGCONTROL_SET_ACCESS_TOKEN_MESSAGE)
        .appendField(new Blockly.FieldTextInput(Blockly.Msg.THINGCONTROL_TOKEN_INPUT_EXAMPLE),
            'token');
		this.setPreviousStatement(true, null);
		this.setNextStatement(true, null);
		this.setColour(225);
		this.setTooltip("");
	}
};

Blockly.Blocks['thingcontrol_send'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.THINGCONTROL_SEND_MESSAGE,
			"args0": [{
				"type": "input_dummy"
			}, {
				"type": "input_value",
				"name": "key",
				"check": "String"
			}, {
				"type": "input_value",
				"name": "message",
				"check": [ "String", "Number", "Boolean" ]
			}],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 225,
			"tooltip": "",
		});
	}
};

/*Blockly.Blocks['thingcontrol_receive_attr'] = {
	init: function() {
	  this.appendDummyInput()
		  .appendField("When Receive Attribute")
		  .appendField(new Blockly.FieldTextInput("attribute"), "temt");
	  this.appendStatementInput("handler")
		  .setCheck(null);
	  this.setInputsInline(false);
	  this.setPreviousStatement(true, null);
	  this.setColour(225);
   this.setTooltip("");
   this.setHelpUrl("");
	}
};*/

Blockly.Blocks['thingcontrol_receive_attr'] = {
		init: function() {
		  this.appendDummyInput()
			  .appendField("When Receive Attribute")
			  .appendField(new Blockly.FieldTextInput("Attribute Name"), "temt");
		  this.appendStatementInput("handler")
			  .setCheck(null);
		  this.setPreviousStatement(true, null);
		  this.setNextStatement(true, null);
		  this.setColour(225);
	   this.setTooltip("");
	   this.setHelpUrl("");
		}
};

Blockly.Blocks['thingcontrol_attr_value'] = {
	init: function() {
	  this.appendDummyInput()
		  .appendField("received text");
	  this.setInputsInline(false);
	  this.setOutput(true, null);
	  this.setColour(225);
   this.setTooltip("");
   this.setHelpUrl("");
	}
};

/*Blockly.Blocks['thingcontrol_gtest'] = {
	init: function() {
		this.appendDummyInput()
        .appendField("GTest")
		this.setPreviousStatement(true, null);
		this.setNextStatement(true, null);
		this.setColour(225);
		this.setTooltip("");
	}
};*/