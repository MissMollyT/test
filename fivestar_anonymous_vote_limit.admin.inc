<?php
/**
 * @file
 * Administrative page callbacks for the fivestar anonymous vote limit module.
 */

/**
 * Form builder. configure limit
 */
 
function fivestar_anonymous_vote_limit_admin_settings() {	
	$limit=variable_get('fivestar_anonymous_vote_limit_limit', _fivestar_anonymous_vote_limit_limit_default());
	
	$form['fivestar_anonymous_vote_limit_limit'] = array(
		'#type'=>'textfield',
		'#title'=>t('vote limit for anonymous user'),
		'#description'=>t('after exceeding the limit anonymous user are unable to vote'),
		'#default_value'=>$limit,
		'#element_validate' => array('element_validate_integer_positive'),
	);
	
	$form['#submit'][]='fivestar_anonymous_vote_limit_admin_settings_submit';
	return system_settings_form($form);
}

/**
 * Process fivestar_anonymous_vote_limit settings submission
 */
function fivestar_anonymous_vote_limit_admin_settings_submit($form, $form_state) {
	variable_set(
		'fivestar_anonymous_vote_limit_limit',
		$form_state['values']['fivestar_anonymous_vote_limit_limit']
	);
}